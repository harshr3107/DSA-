class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        //this is used to map months --> days
        unordered_map<int,int> mp;
        mp[1]=31;
        mp[2]=28;
        mp[3]=31;
        mp[4]=30;
        mp[5]=31;
        mp[6]=30;
        mp[7]=31;
        mp[8]=31;
        mp[9]=30;
        mp[10]=31;
        mp[11]=30;
        mp[12]=31;

        //MM--DD

        int alicearrivalm = stoi(arriveAlice.substr(0,2));
        int alicedeparturem = stoi(leaveAlice.substr(0,2));

        int bobarrivalm = stoi(arriveBob.substr(0,2));
        int bobdeparturem = stoi(leaveBob.substr(0,2));


        int aliced1 = stoi(arriveAlice.substr(3));
        int aliced2 = stoi(leaveAlice.substr(3));

        int bobd1 = stoi(arriveBob.substr(3));
        int bobd2 = stoi(leaveBob.substr(3)); 

        int ans=0;

        int startday;
        int startmonth;
        int endday;
        int endmonth;

        


        if(bobarrivalm>alicearrivalm)
        {
            startmonth = bobarrivalm;
            startday = bobd1;

        }else{

            startmonth = alicearrivalm;
            if(bobarrivalm==alicearrivalm)
            {
                startday=max(aliced1,bobd1);
            }else{
                startday=aliced1;
            }
        }

        if(bobdeparturem>alicedeparturem)
        {
            endmonth=alicedeparturem;
            endday = aliced2;

        }else{
            
            endmonth=bobdeparturem;
            if(bobdeparturem==alicedeparturem)
            {
                //cout<<"mai idher aaya\n";
                endday=min(aliced2,bobd2);
            }else{
                endday=bobd2;
            }

        }

        cout<<"startday startmonth "<<startday<<" "<<startmonth<<" endday endmonth "<<endday<<" "<<endmonth<<endl;

        if(startmonth>endmonth)
        {
            return 0;
        }else if(startmonth==endmonth)
        {
            if(startday>endday)
            {
                return 0;
            }else{

                return endday-startday+1;
            }
        }else{

           // cout<<"yaha3\n";

            ans = mp[startmonth]-startday+1;

           // cout<<"current value of ans is "<<ans<<endl;

            startmonth++;

            while(startmonth!=endmonth)
            {
                ans+=mp[startmonth];
                startmonth++;
            }

            ans+=endday;


        }


        return ans;


        

       
        
    }
};