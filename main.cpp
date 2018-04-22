// lauren defrancesco
// eric schoenborn

#include <vector>
#include <iostream>
int main(int argc, char** argv){

  if(std::stoi(argv[argc-1]) != 0){
    std::cout << "end with 0 " << std::endl;
    return 0;
  }





  for (int f = 1; f < argc-1; f++){


    std::vector<int> val, wt, ans;
    std::vector<std::string> labels;

    // traverse the original cost[] array and skip
    // unavailable packets and make val[] and wt[]
    // array. size variable tells the available number
    // of distinct weighted packets
    int size = 5;
    int W = std::stoi(argv[f]);
  // int W = 29;




    wt.push_back(5);
    wt.push_back(10);
    wt.push_back(14);
    wt.push_back(20);
    wt.push_back(30);


    val.push_back(5);
    val.push_back(10);
    val.push_back(14);
    val.push_back(20);
    val.push_back(30);

    labels.push_back("2h");
    labels.push_back("3l");
    labels.push_back("3h");
    labels.push_back("4l");
    labels.push_back("4h");


    int n = size;
    int min_cost[n+1][W+1];
    int bagWt[n+1][W+1];




    // fill 0th row with infinity
    for (int i=0; i<=W; i++){
      min_cost[0][i] = 0;
      bagWt[0][i]=0;
    }
    // fill 0'th column with 0
    for (int i=1; i<=n; i++){
      min_cost[i][0] = 0;
      bagWt[i][0]=0;
    }

    // now check for each weight one by one and fill the
    // matrix according to the condition
    for (int i=1; i<=n; i++){
      for (int j=1; j<=W; j++){
            // wt[i-1]>j means capacity of bag is
            // less then weight of item
        if (wt[i-1] > j){
          min_cost[i][j] = min_cost[i-1][j];
          bagWt[i][j] = bagWt[i-1][j];
        }else{
          if(wt[i-1]+bagWt[i-1][j]>j && val[i-1] > min_cost[i-1][j]){
           min_cost[i][j]=val[i-1];
           bagWt[i][j]=wt[i-1];
         }else{
           if(min_cost[i-1][j]>min_cost[i][j-1] + val[i-1]){
            min_cost[i][j]=min_cost[i-1][j];
            bagWt[i][j]=bagWt[i-1][j];
          }
          else{
            if(wt[i-1]+bagWt[i-1][j]<=W){
             min_cost[i][j] = min_cost[i-1][j-1]+val[i-1];
             bagWt[i][j]=bagWt[i-1][j-1]+wt[i-1];
           }else{
             if(val[i-1]+min_cost[i-1][j-1]>min_cost[i-1][j] && wt[i-1]+bagWt[i-1][j-1] <= W){
              min_cost[i][j] =val[i-1]+min_cost[i-1][j-1];
              bagWt[i][j]=wt[i-1]+bagWt[i-1][j-1];
            }else{
              min_cost[i][j]=min_cost[i][j-1];
              bagWt[i][j]=bagWt[i][j-1];
            }
          }
        }
      }
    }


  }

}




if(min_cost[5][W-1] != W){

  std::cout << "Case " << f << ": impossible" << std::endl;
}
else{

  int last = 0;
  int top = 0;
  for (int i = 0; i < W; i++){
    if(bagWt[size-1][i] != top){
      for (int j = 0; j < size; j++)
      {
        if(val[j] == bagWt[size-1][i]){
          ans.clear();
          top = val[j];
          ans.push_back(val[j]);
        }
        else if(top+val[j] == bagWt[size-1][i]){
          top = top+val[j];
          ans.push_back(val[j]);

        }
      }
    }
    last = bagWt[size-1][i];

  }
std::cout << "Case " << f << " ";


  for (int i = 0; i < ans.size(); i++){
    for(int j = 0; j<size; j++){
      if(val[j] == ans[i]){
        std::cout << labels[j] << " ";
      }

    }
  }
  std::cout << std::endl;
}


}




}






