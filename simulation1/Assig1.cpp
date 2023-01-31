#include <iostream>
using namespace std;


double calculateYaw(double time, double difference,
    double torque, double& velocity, double& aVelocity, int Iyy, double& yaw);

int main()
{
    double difference = 0.01; 

    //𝑇y(𝑡) = 0.3𝑡 𝑘𝑔𝑚"/𝑠" , the torque applied to helicopter
    const double torque = 0.3;

    double time = 0.0; // 

    double yaw = 0.0; //initial value of yaw 

    double velocity = 0.0; //initial value of velocity  

    double aVelocity = 0.0;
    
    //the moment of intertie of the helicopter in y axis
    int Iyy = 3800;

    for (int x = 0; x < 10; x++)
    {
        //loop for 10 seconds. Each iteration is for 1 second.
        time++;

        yaw = calculateYaw(time, difference, torque, velocity, aVelocity, Iyy, yaw);

        cout << "Execution time in  " << time << "s\n";

        cout << "Yaw value = " << yaw << "\n";

    }
    return 0;
}



//
double calculateYaw(double time, double difference, double torque, double& velocity, double& aVelocity, int Iyy, double& yaw)
{
 
    //In one second  100 steps therefore for loop starts from 100
    for (int i = 100; i > 0; i--) {

        aVelocity = (time * torque);

        double tVelocity = aVelocity / Iyy; 

        velocity += (tVelocity * difference); //   temVelocity * 0.01

        yaw += (velocity * difference);        
    }
    return yaw;
}