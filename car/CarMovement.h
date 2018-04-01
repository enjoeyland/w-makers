class CarMovement {
	private:
		int pin_left_motor_go;
		int pin_left_motor_back;

		int pin_right_motor_go;
		int pin_right_motor_go;

		float car_width;

		float pi = 3.14;

	public:
		CarMovement(
			int _pin_right_motor_go,
			int _pin_right_motor_back,
			int _pin_left_motor_go,
			int _pin_left_motor_back,
			float _car_width);
		~CarMovement();

	public:
		// 앞으로, 뒤로
		void goForward	(float _speed);
		void goBackward	(float _speed);
		void stop (void);
		// 회전
		// 라디안이 아니라 도로
		void turnLeft	(float _average_speed, float _radius);
		void turnLeft	(float _average_speed, float _radius, float _angle);
		void turnRight	(float _average_speed, float _radius);
		void turnRight	(float _average_speed, float _radius, float _angle);
		
		// 제자리리에서 회전
		void spinLeft	(float _average_speed, float _radius);
		void spinLeft	(float _average_speed, float _radius, float _angle);
		void spinRight	(float _average_speed, float _radius);
		void spinRight	(float _average_speed, float _radius, float _angle);

};