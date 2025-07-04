#include <iostream>
        
        
          
          #include <vector>
        
        
          
          using namespace std;
        
        
          
          

        
        
          
          const int MAX = 1000 + 1;
        
        
          
          

        
        
          
          typedef struct
        
        
          
          {
        
        
          
          	bool stop;
        
        
          
          	int leftTime, R, G;
        
        
          
          }Status;
        
        
          
          

        
        
          
          Status trafficLights[MAX];
        
        
          
          

        
        
          
          bool carStop[MAX];
        
        
          
          

        
        
          
          int main(void)
        
        
          
          {
        
        
          
          	ios_base::sync_with_stdio(0);
        
        
          
          	cin.tie(0);
        
        
          
          	int N, L;
        
        
          
          	cin >> N >> L;
        
        
          
          

        
        
          
          	vector<int> locations;
        
        
          
          	
        
        
          
          	for (int n = 0; n < N; n++)
        
        
          
          	{
        
        
          
          		int D, R, G;
        
        
          
          		cin >> D >> R >> G;
        
        
          
          

        
        
          
          		locations.push_back(D);
        
        
          
          		trafficLights[D] = { true, R, R, G };
        
        
          
          	}
        
        
          
          

        
        
          
          	int carLocation = 0;
        
        
          
          	int time = 0;
        
        
          
          

        
        
          
          	while(1)
        
        
          
          	{
        
        
          
          		time++;
        
        
          
          

        
        
          
          		carLocation = trafficLights[carLocation].stop ? carLocation : carLocation + 1;
        
        
          
          

        
        
          
          		if (carLocation == L)
        
        
          
          		{
        
        
          
          			break;
        
        
          
          		}
        
        
          
          
          
          		for (int i = 0; i < locations.size(); i++)
     
        
          
          		{
        
        
          
          			int loc = locations[i];
        
        
          
          

        
        
          
          			if (--trafficLights[loc].leftTime == 0) {
        
        
          
          				trafficLights[loc].stop = !trafficLights[loc].stop;
        
        
          
          

        
        
          
          				trafficLights[loc].leftTime = trafficLights[loc].stop ? trafficLights[loc].R : trafficLights[loc].G;
        
        
          
          			}
        
        
          
          		}
        
        
          
          	}
        
        
          
          

        
        
          
          	cout << time << "\n";
        
        
          
          

        
        
          
          	return 0;
        
        
          
          }
