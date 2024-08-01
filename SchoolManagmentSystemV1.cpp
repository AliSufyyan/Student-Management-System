#include<iostream>
#include<string>
#include<cctype>
using namespace std;
                                // Name  : Ali Sufyyan
                                // Roll# : L1F23BSDS0003
int main()
{
    string Name[10] = {"0"};
    int rollNum[10] = {};
    string FatherName[10] = {};
    string Class[10] = {};    
    string City[10] = {};
    string Grades[10] = {};  

    char option,updateoption,search_choice;
    int limit=0;    
    int option2;
    int roll_num;

    string update_Name,update_Faher_Name,update_Class,update_City,update_Grades;
    string input,searched_name;

    cout<<"\t\tSCHOOL MANAGMENT SYSTEM"<<endl<<endl;

    do
    {
    cout<<"1. Add New Student."<<endl;
    cout<<"2. Show All Student."<<endl;
    cout<<"3. Search Student."<<endl;
    cout<<"4. Update Student Data."<<endl;
    cout<<"5. Remove Student."<<endl;
    cout<<"6. Exit."<<endl<<endl;

    cout<<"Select any option to proceed."<<endl;
    cin>>option;

        switch (option)
        {
            case '1':                                                 //New Student
            cout<<"Enter Name: ";                             //New Student Name
            bool is_valid_name;
            is_valid_name = false;

            while(!is_valid_name)
            {
                cin.ignore();
                getline(cin,input);
                //cin>>input;
                is_valid_name = true;
                for(char c : input)
                {
                    if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                    {
                        is_valid_name = true;
                    }
                    else 
                    {
                        is_valid_name = false;
                        break;
                    }
                }
                if(!is_valid_name)
                {
                    cout<<"Please enter only Alphabets."<<endl;
                    cout<<"Enter Name Again:";
                }
            }

        Name[limit]=input;

        cout<<"Enter Father Name: ";                                //New Father Name
        bool is_valid_fname;
        is_valid_fname = false;

        while(!is_valid_fname)
        {
            cin.ignore();
            getline(cin,input);
            is_valid_fname = true;
            for(char c : input)
            {
                if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                {
                    is_valid_fname = true;
                }
                else
                {
                    is_valid_fname = false;
                    break;
                }
            }
            if(!is_valid_fname)
            {
                cout<<"Please enter only Alphabets."<<endl;
                cout<<"Enter Name Again:";
            }
        }

        FatherName[limit]=input;

        cout<<"Enter Class(without spaces): ";                                          //New Class
        bool is_valid_class;
        is_valid_class  = false;

        while(!is_valid_class)
        {
            cin.ignore();
            getline(cin,input);
            //cin>>input;
            is_valid_class = true;
            for(char c : input)
            {
                if(!isdigit(c))
                {
                    is_valid_class = false;
                    break;
                }

            }
            if(!is_valid_class)
            {
                cout<<"Please enter Correct Class(without spaces)."<<endl;
                cout<<"Enter Class Again:";
            }
        }
        Class[limit] = input;

        cout<<"Enter City: ";                                           //New City
        bool is_valid_city;
        is_valid_city = false;

        while(!is_valid_city)
        {
            cin.ignore();
            getline(cin,input);
            is_valid_city = true;
            for(char c : input)
            {
                if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                {
                    is_valid_city = true;
                }
                else
                {
                    is_valid_city = false;
                    break;
                }
            }
            if(!is_valid_city)
            {
                cout<<"Please enter only Alphabets."<<endl;
                cout<<"Enter City Name Again:";
            }
        }
        City[limit]=input;

        cout<<"Enter Grades(in capital letters): ";                                              //New Grades

        bool is_valid_grade;
        is_valid_grade = false;
        while(!is_valid_grade)
        {
            cin>>input;
            if(input == "A" ||input == "A-" ||input == "B" ||input == "B+"||input == "B-"||input == "C"||input == "C+"||input == "C-"||input == "D"||input == "D+"||input == "F" )
            {
                    is_valid_grade = true;
            }
            else
            {
                    is_valid_grade = false;
                    cout<<"Please enter Correct Grades(in capital letters):";
            }
        }

        Grades[limit]=input;
        rollNum[limit]=limit+1;
        limit++;
        cout<<"Student Added Successfully."<<endl;
        break;

        case '2':                                                 //Show All
        if(Name[0]=="0")
        {
            cout<<"Please Add a student first."<<endl<<endl;
            break;
        }
        for(int i=0; i<limit; i++)
        {
            cout<<"Roll# "<<i+1<<"\t"<<"Name:"<<Name[i]<<"\t"<<"Father Name: "<<FatherName[i]<<"\t";
            cout<<"Class: "<<Class[i]<<"\t"<<"City: "<<City[i]<<"\t"<<"Grades: "<<Grades[i];
            cout<<endl;
        }
        break;

        case '3':                                                 //Searching
        if(Name[0]=="0")
        {
            cout<<"Please Add a student first."<<endl<<endl;
            break;
        }
        cout<<"1. Search via Roll Number."<<endl;
        cout<<"2. Search via Student Name."<<endl;
        cout<<"Enter your choice."<<endl;
        cin>>search_choice;
                    switch(search_choice)
                    {
                        case '1':                                                 //Searching by Roll Number
                                cout<<"Enter student Roll Number to search(without spaces): ";
                                bool is_valid_search_rollno;
                                is_valid_search_rollno  = false;
                                while(!is_valid_search_rollno)
                                {
                                    cin.ignore();
                                    getline(cin,input);
                                    //cin>>input;
                                    is_valid_search_rollno = true;
                                    for(char c : input)
                                    {
                                        if(!isdigit(c))
                                        {
                                            is_valid_search_rollno = false;
                                            break;
                                        }
                                    }
                                    if(!is_valid_search_rollno)
                                    {
                                        cout<<"Please enter Correct Roll Number(without spaces)."<<endl;
                                        cout<<"Enter Roll Number Again:";
                                    }
                                }
                        roll_num = stoi(input);
                        bool is_found_roll_num;
                        int index;
                        for(int i=0; i<limit; i++)
                        {
                            is_found_roll_num = false;
                            if(rollNum[i]==roll_num)
                            {
                                index=i;
                                is_found_roll_num = true;
                                break;
                            }
                        }
                        if(is_found_roll_num)
                        {
                            cout<<endl;
                            cout<<"Name: "<<Name[index]<<endl;
                            cout<<"Father Name: "<<FatherName[index]<<endl;
                            cout<<"Class: "<<Class[index]<<endl;
                            cout<<"City: "<<City[index]<<endl;
                            cout<<endl;
                        }
                        else
                        {
                            cout<<endl;
                            cout<<"Student Not Found."<<endl;
                            cout<<endl;
                        }
                        break;

                        case '2':                                             //Searching by Student
                                cout<<"Enter student Name to search: ";
                                bool is_valid_search_name;
                                is_valid_search_name  = false;
                                while(!is_valid_search_name)
                                {
                                    cin.ignore();
                                    getline(cin,input);
                                    is_valid_fname = true;
                                    for(char c : input)
                                    {
                                        if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                        {
                                            is_valid_name = true;
                                        }
                                        else
                                        {
                                            is_valid_search_name = false;
                                            break;
                                        }
                                    }
                                    if(!is_valid_search_name)
                                    {
                                        cout<<"Please enter only Alphabets."<<endl;
                                        cout<<"Enter Name Again:";
                                    }
                                }
                        searched_name = input;
                        bool is_found_name;
                        int index2;
                        for(int i=0; i<limit; i++)
                        {
                            is_found_name = false;
                            if(Name[i]==searched_name)
                            {
                                index2=i;
                                is_found_name = true;
                                break;
                            }
                        }
                        if(is_found_name)
                        {
                            cout<<endl;
                            cout<<"Name: "<<Name[index2]<<endl;
                            cout<<"Father Name: "<<FatherName[index2]<<endl;
                            cout<<"Class: "<<Class[index2]<<endl;
                            cout<<"City: "<<City[index2]<<endl;
                            cout<<endl;
                        }
                        else
                        {
                            cout<<endl;
                            cout<<"Student Not Found."<<endl;
                            cout<<endl;
                        }
                        break;

                        default:
                        cout<<"invalid option."<<endl;
                        break;
                    }
        break;

        case '4':                                                 //Updation
        if(Name[0]=="0")
        {
            cout<<"Please Add a student first."<<endl<<endl;
            break;
        }
        cout<<"We have below students."<<endl;

        for(int i=0; i<limit; i++)
        {
            cout<<"Roll# "<<i+1<<"\t"<<"Name:"<<Name[i]<<"\t"<<"Father Name: "<<FatherName[i]<<"\t";
            cout<<"Class: "<<Class[i]<<"\t"<<"City: "<<City[i]<<"\t"<<"Grades: "<<Grades[i];
            cout<<endl;
        }

        cout<<"Enter student Roll number to whome you want to update data(without spaces): ";
                bool is_valid_update_rollno;
                is_valid_update_rollno  = false;
                while(!is_valid_update_rollno)
                {
                    cin.ignore();
                    getline(cin,input);
                    is_valid_update_rollno = true;
                    for(char c : input)
                    {
                        cin.ignore();
                        getline(cin,input);
                        //cin>>input;
                        is_valid_update_rollno = true;
                        for(char c : input)
                        {
                            if(!isdigit(c))
                            {
                                is_valid_update_rollno = false;
                                break;
                            }
                    }
                    if(!is_valid_update_rollno)
                    {
                        cout<<"Please enter Correct Roll Number."<<endl;
                        cout<<"Enter Roll Number Again:";
                    }
                }
        roll_num = stoi(input);
        bool found;
        int index2;

        for(int i=0; i<limit; i++)
        {
            found = false;
            if(rollNum[i]==roll_num)
            {
                    index2=i;
                found = true;
                break;
            }
        }
        if(found)
        {
            do
            {
                cout<<"1. Name"<<endl;
                cout<<"2. Father Name"<<endl;
                cout<<"3. Class"<<endl;
                cout<<"4. City"<<endl;
                cout<<"5. Grades"<<endl;
                cout<<"6. All"<<endl;
                cout<<"7. Exit update option."<<endl;

                cout<<"Which credential you want to update(1 to 6)."<<endl;
                cin>>updateoption;

                switch(updateoption)
                {
                    case '1':                                                 //update name
                    cout<<"Enter Name to update:";
                            bool is_valid_update_name;
                            is_valid_update_name = false;
                            while(!is_valid_update_name)
                            {
                                cin.ignore();
                                getline(cin,input);
                                is_valid_update_name = true;
                                for(char c : input)
                                {
                                    if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                    {
                                        is_valid_update_name = true;
                                    }
                                    else
                                    {
                                        is_valid_update_name = false;
                                        break;
                                    }
                                }
                                if(!is_valid_update_name)
                                {
                                    cout<<"Please enter only Alphabets."<<endl;
                                    cout<<"Enter Name Again:";
                                }
                            }
                    Name[index2] = input;
                    cout<<"Name Updated Successfully."<<endl;
                    break;

                    case '2':                                                 //update father nmae
                    cout<<"Enter Father Name to update:";
                                    bool is_valid_update_fname;
                                    is_valid_update_fname = false;
                                    while(!is_valid_update_fname)
                                    {
                                        cin.ignore();
                                        getline(cin,input);
                                        is_valid_update_fname = true;
                                        for(char c : input)
                                        {
                                            if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                            {
                                                is_valid_update_fname = true;
                                            }
                                            else
                                            {
                                                is_valid_update_fname = false;
                                                break;
                                            }
                                        }
                                        if(!is_valid_update_fname)
                                        {
                                            cout<<"Please enter only Alphabets."<<endl;
                                            cout<<"Enter Name Again:";
                                        }
                                    }
                    FatherName[index2] = input;
                    cout<<"Father Name Updated Successfully."<<endl;
                    break;

                    case '3':                                                 //update class
                    cout<<"Enter Class to update(without spaces):";
                                    bool is_valid_update_class;
                                    is_valid_update_class  = false;
                                    while(!is_valid_update_class)
                                    {
                                        cin.ignore();
                                        getline(cin,input);
                                        //cin>>input;
                                        is_valid_class = true;
                                        for(char c : input)
                                        {
                                            if(!isdigit(c))
                                            {
                                                is_valid_class = false;
                                                break;
                                            }
                                        if(!is_valid_update_class)
                                        {
                                            cout<<"Please enter Correct Class(without spaces)."<<endl;
                                            cout<<"Enter Class Again:";
                                        }
                                    }
                    Class[index2] = input;
                    cout<<"Class Updated Successfully."<<endl;
                    break;
                    
                    case '4':                                                 //update City
                    cout<<"Enter City to update:";
                            bool is_valid_update_city;
                            is_valid_update_city = false;
                            while(!is_valid_update_city)
                            {
                                cin.ignore();
                                getline(cin,input);
                                is_valid_update_city = true;
                                for(char c : input)
                                {
                                    if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                    {
                                        is_valid_update_city = true;
                                    }
                                    else
                                    {
                                        is_valid_update_city = false;
                                        break;
                                    }
                                }
                                if(!is_valid_update_city)
                                {
                                    cout<<"Please enter only Alphabets."<<endl;
                                    cout<<"Enter City Name Again:";
                                }
                            }    
                
                    City[index2] = input;
                    cout<<"City  Updated Successfully."<<endl;
                    break;

                    case '5':                                                 //update grades
                    cout<<"Enter Grades to update(In capital letters):";
                                bool is_valid_update__grade;
                                is_valid_update__grade = false;
                                while(!is_valid_update__grade)
                                {
                                    cin>>input;
                                    if(input == "A" ||input == "A-" ||input == "B" ||input == "B+"||input == "B-"||input == "C"||input == "C+"||input == "C-"||input == "D"||input == "D+"||input == "F" )
                                    {
                                            is_valid_update__grade = true;
                                    }
                                    else
                                    {
                                        is_valid_update__grade = false;
                                        cout<<"Please enter Correct Grades(In capital letters):";
                                    }
                                }
                    Grades[index2] = input;
                    cout<<"Grades Updated Successfully."<<endl;
                    break;

                    case '6':                                                 //update all
                                                                        //update name
                    cout<<"Enter Name to update:";
                            bool is_valid_update_all_name;
                            is_valid_update_all_name = false;
                            while(!is_valid_update_all_name)
                            {
                                cin.ignore();
                                getline(cin,input);
                                is_valid_update_all_name = true;
                                for(char c : input)
                                {
                                    if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                    {
                                        is_valid_update_all_name = true;
                                    }
                                    else
                                    {
                                        is_valid_update_all_name = false;
                                        break;
                                    }
                                }
                                if(!is_valid_update_all_name)
                                {
                                    cout<<"Please enter only Alphabets."<<endl;
                                    cout<<"Enter Name Again:";
                                }
                            }
                    Name[index2] = input;

                                                                    //update father nmae
                    cout<<"Enter Father Name to update:";
                                    bool is_valid_update_all_fname;
                                    is_valid_update_all_fname = false;
                                    while(!is_valid_update_all_fname)
                                    {
                                        cin.ignore();
                                        getline(cin,input);
                                        is_valid_update_all_fname = true;
                                        for(char c : input)
                                        {
                                            if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                            {
                                                is_valid_update_all_fname = true;
                                            }
                                            else
                                            {
                                                is_valid_update_all_fname = false;
                                                break;
                                            }
                                        }
                                        if(!is_valid_update_all_fname)
                                        {
                                            cout<<"Please enter only Alphabets."<<endl;
                                            cout<<"Enter Name Again:";
                                        }
                                    }
                    FatherName[index2] = input;
                    

                    cout<<"Enter Class to update(without spaces):";                             //update class
                                    bool is_valid_update_all_class;
                                    is_valid_update_all_class  = false;
                                    while(!is_valid_update_all_class)
                                    {
                                        cin.ignore();
                                        getline(cin,input);
                                        //cin>>input;
                                        is_valid_update_all_class = true;
                                        for(char c : input)
                                        {
                                            if(!isdigit(c))
                                            {
                                                is_valid_update_all_class = false;
                                                break;
                                            }
                                        }
                                        if(!is_valid_update_all_class)
                                        {
                                            cout<<"Please enter Correct Class(without spaces)."<<endl;
                                            cout<<"Enter Class Again:";
                                        }
                                    }
                    Class[index2] = input;
                    
                    
                    cout<<"Enter City to update:";                               //update City
                            bool is_valid_update_all_city;
                            is_valid_update_all_city = false;
                            while(!is_valid_update_all_city)
                            {
                                cin.ignore();
                                getline(cin,input);
                                is_valid_update_all_city = true;
                                for(char c : input)
                                {
                                    if((int(c)>=65 && int(c)<=90) || (int(c)>=97 && int(c)<=122) || int(c)==32)
                                    {
                                        is_valid_update_all_city = true;
                                    }
                                    else
                                    {
                                        is_valid_update_all_city = false;
                                        break;
                                    }
                                }
                                if(!is_valid_update_all_city)
                                {
                                    cout<<"Please enter only Alphabets."<<endl;
                                    cout<<"Enter City Name Again:";
                                }
                            }    
                
                    City[index2] = input;
                                                                    
                    cout<<"Enter Grades to update(in capital letters):";                     //update grades
                                bool is_valid_update_all_grade;
                                is_valid_update_all_grade = false;
                                while(!is_valid_update_all_grade)
                                {
                                    cin>>input;
                                    if(input == "A" ||input == "A-" ||input == "B" ||input == "B+"||input == "B-"||input == "C"||input == "C+"||input == "C-"||input == "D"||input == "D+"||input == "F" )
                                    {
                                            is_valid_update_all_grade = true;
                                    }
                                    else
                                    {
                                        is_valid_update_all_grade = false;
                                        cout<<"Please enter Correct Grades(in capital letters):";
                                    }
                                }
                    Grades[index2] = input;
                    cout<<"All Data Updated Successfully."<<endl;
                    break;
                    
                    case '7':
                    cout<<"Exited From update option.";
                    break;
                    default:
                    cout<<"Invalid Option!"<<endl;
                    break;
                }
            }
        }

                while (updateoption!='7');
            
        }
        else
        {
            cout<<endl;
            cout<<"Student Not Found."<<endl;
            cout<<endl;
        }
        break;

        case '5':                                                     //Removing
        if(Name[0]=="0")
        {
            cout<<"Please Add a student first."<<endl<<endl;
            break;
        }

        cout<<"We have below students."<<endl;

        for(int i=0; i<limit; i++)
        {
            cout<<"Roll# "<<i+1<<"\t"<<"Name:"<<Name[i]<<"\t"<<"Father Name: "<<FatherName[i]<<"\t";
            cout<<"Class: "<<Class[i]<<"\t"<<"City: "<<City[i]<<"\t"<<"Grades: "<<Grades[i];
            cout<<endl;
        }

        cout<<"Enter student Roll number to whome you want to Delete(without spaces): ";
                        bool is_valid_remove_rollno;
                        is_valid_remove_rollno  = false;
                        while(!is_valid_remove_rollno)
                        {
                            cin.ignore();
                            getline(cin,input);
                            //cin>>input;
                            is_valid_remove_rollno = true;
                            for(char c : input)
                            {
                                if(!isdigit(c))
                                {
                                    is_valid_remove_rollno= false;
                                    break;
                                }
                            }
                            if(!is_valid_remove_rollno)
                            {
                                cout<<"Please enter Correct Roll Number(without spaces)."<<endl;
                                cout<<"Enter Roll Number Again:";
                            }
                        }
        roll_num = stoi(input);
        bool roll_found;
        int index3;

        for(int i=0; i<limit; i++)
        {
            if(rollNum[i]==roll_num)
            {
                    index3=i+1;
                roll_found = true;
                break;
            }
        }
        if(roll_found)
        {
                for(int i=index3; i<limit; i++)
                {
                    rollNum[i-1] = rollNum[i];
                    Name[i-1] = Name[i];
                    FatherName[i-1] = FatherName[i];
                    Class[i-1] =Class[i];
                    Grades[i-1] =Grades[i];
                }
                cout<<"Student removed Succeessfully."<<endl;
                limit = limit-1;
            
                        if(index3-1==0)
                    {
                        Name[0]="0";
                    }
        }
        else
        {
            cout<<"Student not found."<<endl;
        }
        break;

        case '6':
        cout<<"Exited Successfully.";
        break;

        default:
        cout<<"Invalid option!"<<endl;
        break;

    }
        }
        } 
    while (option!='6');

    return 0;

}