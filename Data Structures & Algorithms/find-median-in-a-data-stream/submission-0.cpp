class MedianFinder {
private:
    priority_queue<int> leftRoom;
    priority_queue<int,vector<int>,greater<int>> rightRoom;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftRoom.push(num);

        if(!leftRoom.empty() && !rightRoom.empty() && leftRoom.top()>rightRoom.top()){
            rightRoom.push(leftRoom.top());
            leftRoom.pop();
        }

        if(leftRoom.size()>rightRoom.size()+1){
            rightRoom.push(leftRoom.top());
            leftRoom.pop();
        }

        if(rightRoom.size()>leftRoom.size()){
            leftRoom.push(rightRoom.top());
            rightRoom.pop();
        }
    }
    
    double findMedian() {
        if(leftRoom.size()>rightRoom.size())
            return leftRoom.top();
        return (leftRoom.top()+rightRoom.top())/2.0;
    }
};
