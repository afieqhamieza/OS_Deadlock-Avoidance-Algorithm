#include <iostream>
using namespace std;

/*

 my plan:
 1. specify number of process and resource for future use
 2. create matrix of allocation and maximum -> can just take from class exercise
 3. specify the availability
 4. calculate the need of all process
 5. compare need and availability and cout the status
 6. flag and availability updates
 7. sequence result display
 
*/

int main()
{
    int n = 5, m = 3; // n = Number of processes  // m = Number of resources
    
    int resource[5][3] = { { 0, 1, 0 }, // P0
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
    
    int max[5][3] = { { 7, 5, 3 }, // P0
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4
    
    int avail[3] = { 3, 3, 2 }; // Available Resources
    
    int finish[n], ans[n], x=0;
    
    for (int k = 0; k < n; k++)
        finish[k] = 0; //this means all the process has not yet executed completely
    
    int need[n][m];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - resource[i][j];   /*calculating need for each process based on calculation in class*/
    
    for (int k = 0; k < 5; k++)
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                    {
                        cout << "P" << i << " will have to wait..." << endl ;
                        flag = 1;
                        break;
                    }
                
                if (flag == 0)
                {
                    ans[x++] = i;
                    
                    for (int y = 0; y < m; y++)
                        avail[y] += resource[i][y];
                    
                    cout << "executing P" << i << "..." << endl ;
                    finish[i] = 1;
                }
            }
        }

    
    cout << "\nAfter considering all possibilities, \nthe process should follow the sequence below \nin order to avoid deadlock\n" << endl;
    
    for (int i = 0; i < n - 1; i++)
        cout << "P" << ans[i] << " -> " ;
    
    cout << "P" << ans[n - 1] << endl;
    
    return (0);
}
