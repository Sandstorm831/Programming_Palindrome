#include <bits/stdc++.h>
using namespace std;
double func(double x, double y)
{
    double a;
    a = exp(x);
    return a;
}
void Runge_Kutta(void)
{
    double Yi, Xi;
    cout<<"Enter value of x";
    cin>>Xi;
    cout<<endl<<"Enter value of y";
    cin>>Yi;
    double Ai;
    cout<<"Enter value of x to be approximated ";
    cin>>Ai;
    double h = Ai-Xi;
    double k1 = func(Xi, Yi);
    double k2 = func(Xi+h/2, Yi+h*k1/2);
    double k3 = func(Xi+h/2, Yi+h*k2/2);
    double k4 = func(Xi+h,Yi+h*k3);
    double aprox = Yi+((k1+2*k2+2*k3+k4)/6)*h;
    cout<<"Approximate value of function for x = "<<Ai<<" is "<<aprox<<endl;
}
void Adaptive_Runge_Kutta(void)
{
    double Yi, Xi;
    cout<<"Enter value of x";
    cin>>Xi;
    cout<<endl<<"Enter value of y";
    cin>>Yi;
    double Ai;
    cout<<"Enter value of x to be approximated ";
    cin>>Ai;
    double h = Ai-Xi;

    double k1 = func(Xi, Yi);

    double k2 = func(Xi+h/2, Yi+h*k1/2);
    double k3 = func(Xi+h/2, Yi+h*k2/2);
    double k4 = func(Xi+h,Yi+h*k3);
    double normal_step = Yi+h*(k1+2*k2+2*k3+k4)/6;
    
    k2 = func(Xi+h/4, Yi+h*k1/4);
    k3 = func(Xi+h/4, Yi+h*k2/4);
    k4 = func(Xi+h/2,Yi+h*k3/2);
    double half_step = Yi+h*(k1+2*k2+2*k3+k4)/12;

    k2 = func(Xi+h, Yi+h*k1);
    k3 = func(Xi+h, Yi+h*k2);
    k4 = func(Xi+h*2,Yi+h*k3*2);
    double double_step = Yi+h*(k1+2*k2+2*k3+k4)/3;
    // cout<<normal_step<<half_step<<" "<<double_step;
    if(abs(normal_step)>0.1 && abs(normal_step-half_step)/abs(normal_step)>0.01)
    {
        h = h/2;
        Yi = half_step;
        Xi+=h;
        k1 = func(Xi, Yi);
        k2 = func(Xi+h/2, Yi+h*k1/2);
        k3 = func(Xi+h/2, Yi+h*k2/2);
        k4 = func(Xi+h,Yi+h*k3);
        normal_step = Yi+h*(k1+2*k2+2*k3+k4)/6;
        Ai=normal_step;
        cout<<Ai;
    }
    else if(abs(normal_step)>0.1 && abs(double_step-normal_step)/abs(normal_step)<0.005)
    {
        cout<<normal_step;
        h = 2*h;
        Ai = double_step;
    }
    else 
    {
        Ai = normal_step;
        cout<<Ai;
    }

}
void iterative(void)
{
    double Yi, Xi;
    double Y,X;
    cout<<"Enter value of x";
    cin>>Xi;
    cout<<endl<<"Enter value of y";
    cin>>Yi;
    Y=Yi;
    X=Xi;
    double h;
    cout<<"Step size ";
    cin>>h;
    double steps;
    double ho=h;
    cout<<endl<<"number of steps ";
    cin>>steps;
    vector<pair<double,double>> rk;
    vector<pair<double,double>> rka;
    double i=0;
    while(true)
    {
        i++;
        if(i==steps) break;
        double k1 = func(Xi, Yi);
        double k2 = func(Xi+h/2, Yi+h*k1/2);
        double k3 = func(Xi+h/2, Yi+h*k2/2);
        double k4 = func(Xi+h,Yi+h*k3);
        Yi = Yi+h*(k1+2*k2+2*k3+k4)/6;
        Xi = Xi+h;
        rk.push_back(make_pair(Yi, Xi));
    }
    i=0;
    h=ho;
    Xi=X;
    Yi=Y;
    while (true)
    {
        i++;
        if(i==steps) break;
        double k1 = func(Xi, Yi);

        double k2 = func(Xi+h/2, Yi+h*k1/2);
        double k3 = func(Xi+h/2, Yi+h*k2/2);
        double k4 = func(Xi+h,Yi+h*k3);
        double normal_step = Yi+h*(k1+2*k2+2*k3+k4)/6;

        k2 = func(Xi+h/4, Yi+h*k1/4);
        k3 = func(Xi+h/4, Yi+h*k2/4);
        k4 = func(Xi+h/2,Yi+h*k3/2);
        double half_step = Yi+h*(k1+2*k2+2*k3+k4)/12;

        k2 = func(Xi+h, Yi+h*k1);
        k3 = func(Xi+h, Yi+h*k2);
        k4 = func(Xi+h*2,Yi+h*k3*2);
        double double_step = Yi+h*(k1+2*k2+2*k3+k4)/3;

        if(abs(normal_step)>0.1 && abs(normal_step-half_step)/abs(normal_step)>0.2)
        {
            h = h/2;
            Yi = half_step;
        }
        else if(abs(normal_step)>0.1 && abs(double_step-normal_step)/abs(normal_step)<0.05)
        {
            h = 2*h;
            Yi= double_step;
        }
        else Yi = normal_step;
        Xi += h;
        rka.push_back(make_pair(Yi,Xi));
    }
    for(int i=0; i<rk.size(); i++)
    {
        rk[i].first = abs((rk[i].first - exp(rk[i].second))/exp(rk[i].second))*100;
        // cout<<exp(rk[i].second)<<endl;
        rka[i].first = abs((rka[i].first - exp(rka[i].second))/exp(rka[i].second))*100;
    }
    for(int i=0; i<rk.size(); i++)
    {
        cout<<"At x="<<rk[i].second<<" , error is = "<<rk[i].first<<") | ";
    }
    cout<<endl;
    for(int i=0; i<rka.size(); i++)
    {
        cout<<"At x="<<rka[i].second<<" , error is = "<<rka[i].first<<") | ";
    }
}
int main()
{
    // Runge_Kutta(); // comment out to predict a particular value using range Kutta integral
    // Adaptive_Runge_Kutta();  // comment out to predict a particular value using Range Kutta adaptive integral
    iterative();
}
/*
On Running the Code, I have taken the function y=e^x; so if we plug in appropriate values then we can see that 
errors which is on the Adaptive Range Kutta integral is far less than the normal adaptive Range Kutta, also as 
we can see that, Range Kutta Adaptive integral also adapts itself according to the trajectory so In rocket trajectory
we should use Range Kutta integral as that will lead to optimal amount of calcuations depending on the trajectory, if
the trajectory is smooth, it will double the interval, and at more ridge part, or having curves it can half the interval
to better approximate
*/