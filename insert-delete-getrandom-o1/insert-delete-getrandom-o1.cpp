class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> map;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!map.count(val)) {
            nums.push_back(val);
            map[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.count(val)) {
            int last = nums.back();
            map[last] = map[val];
            nums[map[val]] = last;
            nums.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */