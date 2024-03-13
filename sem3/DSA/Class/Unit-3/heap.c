// index starts from 1
// sift version - optimised version
void bot_heap(int *h, int n){
    int i, j, k, key;
    for (k = (n / 2) - 1; k >= 0;k--){
        j = k;
        key = h[j];
        i = 2 * j + 1;
        while(i <= n){
            if(i+1 <= n){
                if(h[i] < h[i+1]){
                    i++;
                }
            }
            if(key < h[i]){
                h[j] = h[i];
                j = i;
                i = 2 * j + 1;
            }
            else{
                break;
            }
        }
        h[j] = key;
    }
}