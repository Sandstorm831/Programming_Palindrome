// Question Link - https://leetcode.com/problems/insert-delete-getrandom-o1/description/
// solution 

class RandomizedSet {
public:
    vector<int> a; 
    unordered_map<int,int> s;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        else
        {
            a.push_back(val);
            s[val]=a.size()-1;
            return true;
        }
    }
    bool remove(int val) {
        if(s.find(val) == s.end())  return false;
        else
        {
            int temp = a.back();
            a[s[val]] = a.back();
            a.pop_back();
            s[temp] = s[val];
            s.erase(val); 
            return true;
        }  
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */