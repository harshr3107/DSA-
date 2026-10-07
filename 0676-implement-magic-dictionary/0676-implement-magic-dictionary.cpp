


class Node
{
    public:

    Node* links[26]{};
    bool flag;

    Node()
    {
        flag=false;
    }


    bool checkif(char a)
    {
        return links[a-'a']==NULL?false:true;
    }

    bool isend()
    {
        return flag==true;
    }

    void addlink(char a,Node* h)
    {
        links[a-'a']=h;
    }

};




class trie
{
    public:

    Node* root;

    trie()
    {
        root = new Node();
    }

    void addnewword(string h)
    {
        Node* temp = root;

        for(int i=0;i<h.length();i++)
        {
                if(temp->checkif(h.at(i))==false)
                {
                     Node* l = new Node();
                     temp->addlink(h.at(i),l);

                }

                temp = temp->links[h.at(i)-'a'];

        }

        temp->flag=true;
  
    }

    bool checkforletter(Node* rot,string& s,int i,int a)
    {
        if(i==s.length())
        {
             return a == 1 && rot->isend();;
        }

        if(a==1)
        {
            if(rot->checkif(s.at(i))==false)
            {
                return false;
            }

            if(checkforletter(rot->links[s.at(i)-'a'],s,i+1,a))
            {
                return true;
            }

        

        }


        for(int j=0;j<26;j++)
        {
            if(rot->links[j]!=NULL)
            {
                if((s.at(i)-'a')==j)
                {
                    if(checkforletter(rot->links[j],s,i+1,a))
                    {
                        return true;
                    }

                }else{

                    if(checkforletter(rot->links[j],s,i+1,a+1))
                    {
                        return true;
                    }



                }

            }
            
        }




        return false;




    }


    bool checkpossible(string& s,int a)
    {

        int i=0;
        Node* temp=root;
        return checkforletter(temp,s,i,a);



    }


   




};






class MagicDictionary {
public:
   
    trie* t;

    MagicDictionary() {

        t = new trie();
        
    }
    
    void buildDict(vector<string> dictionary) {

        for(auto it: dictionary)
        {
            t->addnewword(it);
        }
        
    }
    
    bool search(string searchWord) {

          int a=0;
          return t->checkpossible(searchWord,a);


        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */