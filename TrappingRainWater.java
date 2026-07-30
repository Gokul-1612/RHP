class Solution {
    public int trap(int[] height) {
        int h=height.length;
        int l=0;
        int a[]=new int[h];
        int b[]=new int[h];
       
        a[0]=height[0];
         b[h-1]=height[h-1];
        for(int i=1;i<h;i++){
            a[i]=Math.max(a[i-1],height[i]);

        }
        for(int i=h-2;i>=0;i--){
            b[i]=Math.max(b[i+1],height[i]);
        }
        for(int i=0;i<h;i++){
          l +=(Math.min(a[i],b[i]))-height[i];
            
        }
        return l;
    }
}
