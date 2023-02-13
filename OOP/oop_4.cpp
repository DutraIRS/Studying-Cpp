#include <iostream>

class Oven{
    private:
        int temperature;
    
    public:
        Oven(int temperature = 0){
            setTemperature(temperature);
        }

        void setTemperature(int temperature){
            if (temperature < 0){
                this->temperature = 0;
            } else if (temperature > 300){
                this->temperature = 300;
            } else {
                this->temperature = temperature;
            }
        }

        int getTemperature(){
            return this->temperature;
        }
};

int main (){
    Oven oven1(100);
    Oven oven2(400);
    Oven oven3(-100);

    std::cout << oven1.getTemperature() << std::endl;
    std::cout << oven2.getTemperature() << std::endl;
    std::cout << oven3.getTemperature() << std::endl;

    return 0;
}