class D2Vector {
	public:
		float v_x;
		float v_y;

	public:
		D2Vector();
		~D2Vector();
		D2Vector(float _x, float _y);

	public:
		float getSize(void);
		float getDirection(void);
		
		// +, +=
		D2Vector 	operator + 	(D2Vector _vector);
		D2Vector& 	operator += (D2Vector _vector);

		// -, -=
		D2Vector 	operator - 	(D2Vector _vector);
		D2Vector& 	operator -= (D2Vector _vector);

		// *, *=
		D2Vector 	operator * 	(float _scalar);
		D2Vector& 	operator *= (float _scalar);

		float gainAngle(D2Vector _vector);
};