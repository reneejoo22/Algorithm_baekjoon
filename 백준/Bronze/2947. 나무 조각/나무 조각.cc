#include <iostream>

int arr[6] = {0};
int tmp;
int main(int argc, char** argv){
  for(int i = 1; i <= 5; i++){
    scanf("%d", &arr[i]);
  }

  while(arr[1] != 1 || arr[2] != 2 || arr[3] != 3 || arr[4] != 4 || arr[5] != 5){
    
      for(int i = 1; i < 5; i++){ 
      if(arr[i] > arr[i+1]){
        tmp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = tmp;
        for(int j = 1; j <= 5; j++){
          printf("%d ", arr[j]);
        }
        printf("\n");
        continue;
      }
    }
  }

  return 0;
}