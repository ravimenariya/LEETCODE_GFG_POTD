class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<classes.size();i++){
            int p=classes[i][0],t=classes[i][1];
            double inc=(double)(p+1)/(t+1) - (double)p/t;
            pq.push({inc,i});
        }

        while(extraStudents)
        {
            auto top=pq.top();
            pq.pop();
            int i=top.second;
            classes[i][0]++;
            classes[i][1]++;

            int p=classes[i][0],t=classes[i][1];
            double inc=(double)(p+1)/(t+1) - (double)p/t;
            pq.push({inc,i});

            extraStudents--;
        }    
        double sum=0;

        for(int i=0;i<classes.size();i++){
            sum+=((double)classes[i][0]/classes[i][1]);
        }

        return (float)sum/classes.size();
    }
};
