#include <stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE][MAX_SIZE];
 int size_array_2  = 0;
 int size_array_3   = 0;
 int max_2 = 0;
 int max_3 = 0;

void flood_fill_1(int x, int y, int m, int n) {
    

    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }
    if (arr[x][y] == 1) {
        arr[x][y] = 2; // Change 1 to 2
        size_array_2++;
    flood_fill_1(x + 1, y, m, n);
    flood_fill_1(x - 1, y, m, n);
    flood_fill_1(x, y + 1, m, n);
    flood_fill_1(x, y - 1, m, n);
    }
   
    else{
        return;
    }
    
    
}
void flood_fill_0(int x, int y, int m, int n) {
    

    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }
    if(arr[x][y] == 0){
    arr[x][y] = 3; // Change 0 to 3
    size_array_3++;
    flood_fill_0(x + 1, y, m, n);
    flood_fill_0(x - 1, y, m, n);
    flood_fill_0(x, y + 1, m, n);
    flood_fill_0(x, y - 1, m, n);
    }
    else{
        return;
    }
    
    
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n); 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]); 
        }
    }
 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[i][j] == 0){
            max_3 = size_array_3;
            // size_array_3 =0;
              
              
                
                if(max_3 > size_array_3){
                size_array_3 =0;
                }
                else if(max_3 < size_array_3){ 
                    max_3 = size_array_3;
                }
            flood_fill_0(i, j, m, n);
             printf("size_array_3   :  %d\n" ,size_array_3 );
            }
            else if(arr[i][j] == 1){
                size_array_2 =0;
            flood_fill_1(i, j, m, n);
             printf("size_array_2   :  %d\n" ,size_array_2 );
            }
            
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
      printf("%d\n" ,max_3 );
    //  printf("%d\n" ,size_array_3 );
    return 0;
}
