#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct operation
{
    char command;
    //erased part
    string argument;
};

int main()
{
    //number of queries
    int q;
    cin >> q;

    //our string to start with
    string s = "";
    vector<operation> superhero;
    vector<operation> sidekick;
    bool phased=false;

    char command;
    while(q)
    {
        q--;
        cin >> command;
        if(command=='a')
        {
            if(phased)
            {
                superhero.clear();
                sidekick.clear();
                phased=false;
            }
            string w;
            cin >> w;
            s = s+w;

            operation new_ops;
            new_ops.command='a';
            new_ops.argument=w;
            superhero.push_back(new_ops);
            cout << "append: " << w << ": " << s << endl;
        }
        else if(command=='e')
        {
            if(phased)
            {
                superhero.clear();
                sidekick.clear();
                phased=false;
            }
            int k;
            cin >> k;

            operation new_ops;
            new_ops.command='e';
            new_ops.argument=s.substr(s.size()-k);
            superhero.push_back(new_ops);

            s.erase(s.end()-k,s.end());
            cout << "erase: " << new_ops.argument << ": " << s << endl;
        }
        else if(command=='g')
        {
            int k;
            cin >> k;
            cout << k << ": " << s << ": " << s[k] << endl;
        }
        else if(command=='u')
        {
            phased=true;
            if(superhero.size()>0)
            {
                operation undoing = superhero.back();
                sidekick.push_back(undoing); 
                superhero.pop_back();

                if(undoing.command=='a')
                {
                    s.erase(s.end()-undoing.argument.size(),s.end());
                }
                else if(undoing.command=='e')
                {
                    s = s+undoing.argument;
                }
            }
            cout << "undo: " << s << endl;
        }
        else if(command=='r')
        {
            phased=true;
            if(sidekick.size()>0)
            {
                operation redoing = sidekick.back();
                superhero.push_back(redoing);
                sidekick.pop_back();

                if(redoing.command=='a')
                {
                    s = s+redoing.argument;
                }
                else if(redoing.command=='e')
                {
                    s.erase(s.end()-redoing.argument.size(),s.end());
                }
            }
            cout << "redo: " << s << endl;
        }
    }
}
