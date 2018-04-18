#ifndef CAR_CARMOVEMENT_H
#define CAR_CARMOVEMENT_H

//namespace carMovement {

	class CarMovement {
	protected:
		int pin_left_motor_go;
		int pin_left_motor_back;
		int pin_right_motor_go;
		int pin_right_motor_back;

		float car_width;

		const float PI = 3.14;

	public:
		CarMovement(
				int pin_left_motor_go,
				int pin_left_motor_back,
				int pin_right_motor_go,
				int pin_right_motor_back,
				float car_width);

		~CarMovement();

	public:
		// 앞으로, 뒤로
		void goForward(const float &speed, float distance = 0);

		void goBackward(const float &speed, float distance = 0);

		void stop();

		// 회전
		// 라디안이 아니라 도로
		void turnLeft(const float &average_speed, const float &radius, const float &degree = 0);

		void turnRight(const float &average_speed, const float &radius, const float &degree = 0);

		// 제자리리에서 회전
		void spinLeft(const float &average_speed, const float &radius, const float &degree = 0);

		void spinRight(const float &average_speed, const float &radius, const float &degree = 0);

	protected:
		virtual void setMotorSpeed(const float &right_speed, const float &left_speed) = 0;

		inline float getAngularSpeed(const float &average_speed, const float &radius);

//	inline float getRadian(const float &degree);
		inline void turnSpecificDegree(const float &angular_speed, const float &degree);

	};

	class CarMovementAnalog : public CarMovement {
	public:
		CarMovementAnalog(int pin_left_motor_go,
				int pin_left_motor_back,
				int pin_right_motor_go,
				int pin_right_motor_back,
				float car_width):
		CarMovement(pin_left_motor_go, pin_left_motor_back, pin_right_motor_go, pin_right_motor_back, car_width) {};
		~CarMovementAnalog();
	public:
		virtual void setMotorSpeed(const float &right_speed, const float &left_speed);

	};

	class CarMovementDigital : public CarMovement {
	public:
		CarMovementDigital(int pin_left_motor_go,
				int pin_left_motor_back,
				int pin_right_motor_go,
				int pin_right_motor_back,
				float car_width):
		CarMovement(pin_left_motor_go, pin_left_motor_back, pin_right_motor_go, pin_right_motor_back, car_width) {};
		~CarMovementDigital();
	public:
		virtual void setMotorSpeed(const float &right_speed, const float &left_speed);
	};
//}
#endif //CAR_CARMOVEMENT_H