class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ans=(ax2-ax1)*(ay2-ay1);
        ans+=(bx2-bx1)*(by2-by1);
        int cx1,cx2,cy1,cy2;
        cx1=max(ax1,bx1);
        cx2=min(ax2,bx2);
        cy2=min(by2,ay2);
        cy1=max(ay1,by1);
        if(cy2>=cy1&&cx1<=cx2){
            ans-=(cx2-cx1)*(cy2-cy1);
        }
        return ans;
    }
};