
// Prblem -> https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=daily-question&envId=2025-03-21

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size(),curr=0;
        vector<string>ans;
        unordered_map<string,bool>aval;
        for(auto&i:supplies)    aval[i]=true;
        while(curr<n){
        bool mf=0;
        for(int i=0;i<ingredients.size();i++)
        {
            bool a=1;
            for(auto&j:ingredients[i])
            {
                if(!aval[j])
                {
                    a=0;
                    break;
                }
            }
            if(a)   
            {
                ans.push_back(recipes[i]);
                aval[recipes[i]]=true;
                curr++;
                mf=1;
                ingredients.erase(ingredients.begin()+i);
                recipes.erase(recipes.begin()+i);
            }
        }
        if(!mf) break;
        }
        return ans;
    }
};
