class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ingre, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> supp(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> unprep;
        unordered_set<string> pending; // Keeps track of recipes that need to be rechecked

        // First pass: Identify directly possible recipes & store unprepared ones
        for (int i = 0; i < rec.size(); i++) {
            bool all_ing = true;
            for (string& ing : ingre[i]) {
                if (supp.find(ing) == supp.end()) {
                    all_ing = false;
                    unprep[rec[i]].push_back(ing);
                }
            }
            if (all_ing) {
                ans.push_back(rec[i]);
                supp.insert(rec[i]);
            } else {
                pending.insert(rec[i]);
            }
        }

        // Second pass: Iteratively check unprepared recipes
        bool progress = true;
        while (progress) {
            progress = false;
            for (auto it = pending.begin(); it != pending.end();) {
                string recipe = *it;
                vector<string>& missing = unprep[recipe];

                // Remove available ingredients
                missing.erase(remove_if(missing.begin(), missing.end(), [&](const string& ing) {
                    return supp.find(ing) != supp.end();
                }), missing.end());

                // If all ingredients are now available, add recipe to answer
                if (missing.empty()) {
                    ans.push_back(recipe);
                    supp.insert(recipe);
                    it = pending.erase(it); // Erase from pending
                    progress = true;  // Keep iterating
                } else {
                    ++it;
                }
            }
        }

        return ans;
    }
};
