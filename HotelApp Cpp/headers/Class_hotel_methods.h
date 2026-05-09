Hotel::Hotel(){
    counter1 = 0;
    counter2 = 0;
    room_management();
}

void Hotel::room_management(){
    int number;

    for(int i = 0; i <= 20; i++){
        rooms[i] = empty_room;
    }

    do {
        cout << "\n\t -- OTEL AR --\n";
        cout << "\t1. Oda Rezervasyonu\n";
        cout << "\t2. Oda Bosaltma\n";
        cout << "\t3. Dolu Oda Sayisi\n";
        cout << "\t4. Oda Raporu\n";
        cout << "\t5. Toplam Gelir\n";
        cout << "\t6. Cikis yap\n";
        cout << "Secimini Gir:";
        cin >> number;
        
        switch(number){
            case 1: room_reservation(); break;
            case 2: room_evacuation(); break;
            case 3: number_of_rooms(); break;
            case 4: room_report(); break;
            case 5: income(); break;
            case 6: cout << "Cikis yapiliyor...\n"; break;
            default: cout << "Yanlis deger girdiniz 1-6 arasi deger girin\n";
        }
    } while(number != 6); 
}

void Hotel::room_reservation(){
    int number, numberofdays, i = 1, j = 13;
    string name, lastname;
    
    cout << "\n\t-lutfen oda tipi secin-\n";
    cout << "\t1. 1 kisilik oda (600 TL)\n";
    cout << "\t2. 2 kisilik oda (1000 TL)\n";
    cout << "oda secimini gir:";
    cin >> number;
    
    switch(number){
        case 1:
            for(; i <= 12; i++){
                if(rooms[i] != full_room){
                    rooms[i] = full_room;
                    cout << "adiniz:";
                    cin >> name;
                    cout << "soyadiniz:";
                    cin >> lastname;
                    cout << "Kac gun kalacaksiniz:";
                    cin >> numberofdays;
                    sum += numberofdays * 600;
                    counter1++;
                    customer_name[i] = new string;
                    *customer_name[i] = name;
                    customer_lastname[i] = new string;
                    *customer_lastname[i] = lastname;
                    break;
                }   
            }
            if(i > 12){
                cout << "butun tek kisilik odalar doldu\n";
            }
            break;
        
        case 2:
            for(; j <= 20; j++){
                if(rooms[j] != full_room){
                    rooms[j] = full_room;
                    cout << "adiniz:";
                    cin >> name;
                    cout << "soyadiniz:";
                    cin >> lastname;
                    cout << "Kac gun kalacaksiniz:";
                    cin >> numberofdays;
                    sum += numberofdays * 1000;
                    counter2++;
                    customer_name[j] = new string;
                    *customer_name[j] = name;
                    customer_lastname[j] = new string;
                    *customer_lastname[j] = lastname;
                    break;
                }   
            }
            if(j > 20){
                cout << "butun iki kisilik odalar doldu\n";
            }
            break;
        
        default:
            cout << "oda turunu yanlis bir deger girdiniz\n";
    }
}

void Hotel::room_evacuation(){
    int number;
    cout << "bosaltilacak oda numarasini gir:";
    cin >> number;
    
    if(rooms[number] == full_room){
        rooms[number] = empty_room;
        delete customer_name[number];
        delete customer_lastname[number];
        
        if(number > 0 && number <= 12)
            counter1--;
        else if(number > 12 && number <= 20)
            counter2--;
            
        cout << "oda artik bos\n";
    }
    else{
        cout << "bu oda zaten bos\n";
    }
}

void Hotel::number_of_rooms(){
    cout << "dolu olan 1 kisilik oda sayisi:" << counter1 << "\n";
    cout << "dolu olan 2 kisilik oda sayisi:" << counter2 << "\n";
}

void Hotel::room_report(){
    if(counter1 == 0 && counter2 == 0){
        cout << "butun odalar bos\n";
    }
    else{
        cout << "oda numarasi\t musteri adi\t musteri soyadi\n";
        cout << "===============================================\n";
        for(int i = 1; i <= 20; i++){
            if(rooms[i] == full_room){
                cout << i << "\t\t " << *customer_name[i] << "\t\t " << *customer_lastname[i] << "\n";
            }
        }
    }
}   

void Hotel::income(){
    cout << "toplam gelir:" << sum << "\n";
}