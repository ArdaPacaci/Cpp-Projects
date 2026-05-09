class Hotel{
	string *customer_name[21];
	string *customer_lastname[21];
	
	int sum=0, counter1, counter2;
	
	enum status{
		empty_room,
		full_room

	} rooms[21]; 
	
	public:
		Hotel();
		void room_management();
		void room_reservation();
		void room_evacuation();
		void number_of_rooms();
		void room_report(); 
		void income();
};