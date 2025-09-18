class TaskManager {
    unordered_map<int,pair<int,int>>ump;//taskid,<priority,userid>
    set<pair<int,int>>st; // priority,taskid
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
        {
            ump[tasks[i][1]]=make_pair(tasks[i][2],tasks[i][0]);
            st.insert({tasks[i][2],tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ump[taskId]=make_pair(priority,userId);
        st.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto p=ump[taskId];
        st.erase({p.first,taskId});
        st.insert({newPriority,taskId});
        p.first=newPriority;
        ump[taskId]=p;
    }
    
    void rmv(int taskId) {
        int priority=ump[taskId].first;
        st.erase({priority,taskId});
        ump.erase(taskId);
    }
    
    int execTop() {
        if(st.empty())  return -1;
        auto exec=*st.rbegin();
        int userid=ump[exec.second].second;
        ump.erase(exec.second);
        st.erase(exec);
        return userid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
