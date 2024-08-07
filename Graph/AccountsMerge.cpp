class Solution {
public:

    // teaches me union find 
    vector<int>parent;
    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y){
        int xParent = findParent(x);
        int yParent = findParent(y);

        if(xParent != yParent){
            parent[xParent] = yParent;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for(int i = 0; i < n ; i++){
            parent[i] = i;
        }

        // maps all the mails to their id
        unordered_map<string, int> mailToid;
        for(int i = 0; i < n; i++){

            // accounts[i].size() ==> bcz not all of people have same no. of emails
            for(int j = 1; j < accounts[i].size(); j++){

                string email = accounts[i][j];
                // means email is not in the map
                if(mailToid.find(email) == mailToid.end()){
                    // mapping email with its row numbers (id)
                    mailToid[email] = i;
                }
                else {
                    // mail is already added now unioning them to a fixed user
                    Union(i , mailToid[email]);
                }
            }
        }


        unordered_map<int, vector<string>> finalMap;

        for(auto &pairi : mailToid){
            string email = pairi.first;
            int person = findParent(pairi.second);
            finalMap[person].push_back(email);
        }

        // final ans vvstring

        vector<vector<string>> ans;

        for(auto &pairi : finalMap){
            int person = pairi.first;  // id of person ( index value )
            vector<string> list = pairi.second;  // vector of emails of that person
            sort(list.begin() , list.end());

            vector<string> temp;

            temp.push_back(accounts[person][0]);

            for(auto &email : list){
                temp.push_back(email);
            }
            // after one person is completed 
            ans.push_back(temp);
        }

        return ans;
    }
};
