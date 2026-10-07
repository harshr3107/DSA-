

class Node
{

    public:

    Node* links[26]{};
    bool isflag;

     Node()
    {
        isflag=false;
    }

    bool isend()
    {
        return isflag;
    }


    bool checkif(char a)
    {
        return links[a-'a']==NULL?false:true;
    }


    void addlink(char h,Node* l)
    {
        links[h-'a']=l;

    }




};



class trie
{

    public:

    Node* root;

    trie()
    {
        root=new Node();
    }



    void addword(string& s,string& ans)
    {
        Node* temp = root;
        bool isend=true;

        for(int i=0;i<s.length();i++)
        {
             if(temp->checkif(s.at(i))==false)
             {
                Node* h = new Node();
                temp->addlink(s.at(i),h);
                
                if(i!=s.length()-1)
                {
                    //cout<<"mai yaha pe aayi for "<<s.at(i)<<endl;
                    isend=false;
                }
             }

            

             temp = temp->links[s.at(i)-'a'];
             if(temp->isflag==false && i!=s.length()-1)
             {
                 //cout<<"mai yaha pe aayi for--2"<<s.at(i)<<endl;
                isend=false;
             }


        }

        temp->isflag=true;

        if(isend==true)
        {
            if(ans.length()<s.length())
            {
                ans=s;
            }
        }

    }



};








class Solution {
public:




    string longestWord(vector<string>& words) {

        sort(words.begin(),words.end());
        string ans="";

        trie* t = new trie();

        for(auto it: words)
        {

            //cout<<"i am adding "<<it<<endl;

            t->addword(it,ans);



        }


        return ans;
        
    }
};