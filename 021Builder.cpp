#include<iostream>
#include<string>
#include<list>
using namespace std;
namespace nm021
{
	class Vehicle
	{
	public:
		string wheels;
		string body;
		string steering;
		string engine;
		string seats;
	};

	class VehicleBuilder
	{
	protected:
		Vehicle *vehicle;
	public:
		void SetVehicle(Vehicle *vehicle)
		{
			this->vehicle = vehicle;
		}
		virtual void SetWheels() = 0;
		virtual void SetBody() = 0;
		virtual void SetSteering() = 0;
		virtual void Setengine() = 0;
		virtual void SetSeats() = 0;
	};


	class Truck :public Vehicle
	{
	public:
		void DisplayTruck()
		{
			cout << "Truck details " << endl;
			cout << wheels << endl;
			cout << body << endl;
			cout << steering << endl;
			cout << engine << endl;
			cout << seats << endl;
		}
	};

	class Car :public Vehicle
	{
	public:
		void DisplayCar()
		{
			cout << "Car details " << endl;
			cout << wheels << endl;
			cout << body << endl;
			cout << steering << endl;
			cout << engine << endl;
			cout << seats << endl;
		}
	};

	class MercedezTruck :public  VehicleBuilder
	{

	public:

		void SetWheels()
		{
			vehicle->wheels = "12 Alloy wheels";
		}
		void SetBody() {
			vehicle->body = "Steel ";
		}
		void SetSteering() {
			vehicle->steering = "Copper";
		}
		void Setengine() {
			vehicle->engine = "6 strokes";
		}
		void SetSeats() {
			vehicle->seats = "Cushion seats";
		}
	};

	class TataTruck :public  VehicleBuilder
	{
	public:
		void SetWheels()
		{
			vehicle->wheels = "10 Alloy wheels";
		}
		void SetBody() {
			vehicle->body = "Iron ";
		}
		void SetSteering() {
			vehicle->steering = "Plastic";
		}
		void Setengine() {
			vehicle->engine = "4 strokes";
		}
		void SetSeats() {
			vehicle->seats = "iron";
		}
	};


	class TataCar :public  VehicleBuilder
	{
	public:
		void SetWheels()
		{
			vehicle->wheels = "4 Alloy wheels";
		}
		void SetBody() {
			vehicle->body = "Ploastic ";
		}
		void SetSteering() {
			vehicle->steering = "Plastic";
		}
		void Setengine() {
			vehicle->engine = "auto engine";
		}
		void SetSeats() {
			vehicle->seats = "leather";
		}
	};


	class Director
	{
	public:
		void BuildParts(Vehicle *vehicle, VehicleBuilder *builder)
		{
			builder->SetVehicle(vehicle);
			builder->SetBody();
			builder->Setengine();
			builder->SetWheels();
			builder->SetSteering();
			builder->SetSeats();
		}
	};

	void main()
	{
		Truck truck;
		Car car;
		TataTruck truckBuilder;
		TataCar carBuilder;
		Director director;
		director.BuildParts(&car, &carBuilder);
		director.BuildParts(&truck, &truckBuilder);
		car.DisplayCar();
		cout << "__________________________" << endl;
		truck.DisplayTruck();

	}
}