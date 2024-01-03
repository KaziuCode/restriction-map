#include <iostream>
#include <fstream>
#include<algorithm>
#include <bits/stdc++.h>
#include<vector>
#include<numeric>
#include<stdlib.h>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <cmath>

using std::vector;

using namespace std;
class Timer
{
public:
    void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }

    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }

    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool                                               m_bRunning = false;
};


int dlugosc(int k,long long wynik,int rozmiar,int dlugoscmapy,long long silnia1=1,long long silnia2=1)
{


    silnia1=1;
    for(int i =k; i>1; i--)
    {
        silnia1*=i;


    }
    int  b=(k-2);
    silnia2=1;
    for(int i=b; i>1; i--)
    {
        silnia2*=i;


    }
    wynik=(silnia1/2);
    wynik=(wynik/silnia2);
    if(rozmiar==wynik)
    {
        cout<<"istnieje rozwiazanie "<<endl;
        dlugoscmapy = k-2;
        return dlugoscmapy;

    }
    else
    {
        return dlugoscmapy = 0;
    }



}

void reku(vector <int> v,vector <int> uzyte,vector <int> iteracje,vector<int> uzytehelp,vector<int>iteracjehelp,vector <int> mapa,int temp,int maks,int dlugoscmapy,int temp2,bool warunek1,bool warunek2,int sumy,Timer czas)
{






    if(dlugoscmapy-mapa.size()==1)
    {

        int ostatni = maks-(accumulate(mapa.begin(),mapa.end(),0));
        for(int last=0; last<v.size(); last++)
        {
            if(v[last]==ostatni&&iteracje[last]==(mapa.size()-1))
            {
                mapa.push_back(v[last]);

                for (int a : mapa){
                    cout << a << " ";
                }
                    cout << " rozwiazanie"<<endl;czas.stop();


    std::cout << "Sekundy: " << czas.elapsedSeconds() << std::endl;
    std::cout << "Milisekundy: " << czas.elapsedMilliseconds() << std::endl
    ;
                    getch();


            }


        }

        temp=v.size();
    }


        for(int x=temp; x<v.size(); x++)
        {
            for (int help=0; help<uzyte.size(); help++){
        uzytehelp[help]=uzyte[help];}
        for (int help4=0; help4<iteracje.size(); help4++){
        iteracjehelp[help4]=iteracje[help4];
            }
            if(uzyte[x]==0)
            {
                uzytehelp[x]=1;
                iteracjehelp[x]=mapa.size();

                int odleglosc=(maks-(accumulate(mapa.begin(),mapa.end(),v[x])));




                if(odleglosc>=0){
                for(int w1=0; w1<v.size(); w1++)
                {
                    if(v[w1]==odleglosc&&uzytehelp[w1]==0)
                    {

                        warunek1=true;
                        uzytehelp[w1]=1;
                        iteracjehelp[w1]=mapa.size();
                        break;
                    }
                }
                }else{break;}
                if(warunek1==true){
                        for(int l=0; l<mapa.size(); l++)
                        {   warunek2=false;
                            sumy=accumulate(mapa.begin() +l,mapa.end(),v[x]);


                            for(int w2=0; w2<v.size(); w2++)
                            {
                                if(v[w2]==sumy&&uzytehelp[w2]==0)
                                {

                                    warunek2=true;
                                    uzytehelp[w2]=1;
                                    iteracjehelp[w2]=mapa.size();
;
                                    break;
                                }

                            }
                            if(warunek2==false){

                                break;
                            }

                        }
                        if(warunek1==true&&warunek2==true)
                        {

                             for (int help5=0; help5<uzyte.size(); help5++){
        uzyte[help5]=uzytehelp[help5];}
        for (int help6=0; help6<iteracje.size(); help6++){
        iteracje[help6]=iteracjehelp[help6];}
        mapa.push_back(v[x]);


if(temp2!=0){
                            temp=temp2;}else{temp=0;}
                            temp2=0;




                            /* for (int ttt : mapa)
		cout << ttt << " ";
    cout<<" :mapa good"<<endl;
    for (int ttt1 : iteracje)
		cout << ttt1 << " ";
		cout<<" :iteracje  good"<<endl;*/



                            reku(v,uzyte,iteracje,uzytehelp,iteracjehelp,mapa,temp,maks,dlugoscmapy,temp2,false,false,0,czas);
                        }
                }



                    }




        }



          int elemntymapy=(mapa.size()-1);
                            int xxx=mapa[elemntymapy];
                             for(int xxx2=(v.size()-1);xxx2>=0;xxx2--){
                                if(v[xxx2]==xxx){
                                    temp=xxx2+1;
                                    break;
                                }}


                          //  if(elemntymapy==0){temp2=0;}else{
                           int xx=mapa[elemntymapy-1];


                               for(int xx2=(v.size()-1);xx2>=0;xx2--){
                                if(v[xx2]==xx){
                                    temp2=xx2+1;
                                    break;
                                }}
                                if(temp2=0){
                                    cout<<"zly temp"<<endl;
                                    getch();
                                }

                             //   }
//





                            for(int usun=0; usun<v.size(); usun++)
                            {
                                if(iteracje[usun]==(mapa.size()-1))
                                {
                                    uzyte[usun]=0;
                                    iteracje[usun]=0;
                                }
                            }
                            mapa.pop_back();
                            //mapa.pop_back();
                            for (int helpp=0; helpp<uzyte.size(); helpp++){
        uzytehelp[helpp]=uzyte[helpp];}
        for (int helpa=0; helpa<iteracje.size(); helpa++){
        iteracjehelp[helpa]=iteracje[helpa];
            }
/*
        for (int tt : mapa)
		cout << tt << " ";
    cout<<" mapa bad"<<endl;
*/







                            reku(v,uzyte,iteracje,uzytehelp,iteracjehelp,mapa,temp,maks,dlugoscmapy,temp2,false,false,0,czas);




        }




int main()
{   int indeks=0;
    long long silnia1=1;
    long long silnia2=1;
    int g;
int pierwszyel;
int rozmiar = 0 ;
    int k;
    int wyniknewtona= 0;
long long wynik;
    int dlugoscmapy=0;
    int temp;
    vector<int> v;
    vector<int> v1;
    vector<int> v2;

ifstream inFile;

int x;
int u1;
int u2;
vector<int>mapa;

    inFile.open("testy8.txt", ios::in);

    if (!inFile)
    {
        cerr << "Can't open input file " << endl;
        exit(1);
    }


    while (inFile >> x)
    {

        temp =x;
        v.push_back(temp);

        rozmiar++;

    }

    inFile.close();
    sort(v.begin(), v.end());

	//tworzenie nowego wektora
		for (int i=0; i<v.size(); i++)
        v2.push_back(v[i]);

    cout<<rozmiar<<" rozmiar multizbioru"<<endl;


rozmiar=v2.size();
    for(k = 4; k<20; k++)
    { wyniknewtona = dlugosc(k,wynik,rozmiar,dlugoscmapy,silnia1,silnia2);
     if(wyniknewtona!=0){

            break;
        }
    }
    cout<<wyniknewtona<<" ilosc ciec"<<endl;
    if(wyniknewtona==0){
        cout<<"nie istnieje rozwiazanie"<<endl;
        getch();
    }



    int my = v.size();
    int maks = v[my-1];

    pierwszyel = ((v2[rozmiar-1])-(v2[rozmiar-2]));
    cout<<pierwszyel<<" pierwszy element mapy"<<endl;
    mapa.push_back(pierwszyel);

    int temp2;
   // cout <<my<<" dlugosc przed usunieciem"<<endl;
    if (count(v2.begin(), v2.end(), pierwszyel))
    {
        cout << "Element obecny w zbiorze"<<endl;
        for(temp = 0; temp<v2.size(); temp++)
        {
            temp2=v2[temp];
            if(temp2==pierwszyel)
            {
                v2.erase(v2.begin() + temp);
                v2.erase(v2.end() - 1);
                v2.erase(v2.end() - 1);
                break;
            }
        }
    }


    else
    {
        cout << "Elementu 1 nie ma w zbiorze";
        getch();

    }
    int my2 = v2.size();
    vector<int> vect1(my2, 0);
    vector<int> vect2(my2, 0);
    vector<int> vect3(my2, 0);
    vector<int> vect4(my2, 0);

   // cout <<my2<<" dlugosc po usunieciu"<<endl;

   // cout<<maks<<"wartosc maks"<<endl;
  /*  for (int x : v2){
		cout << x << " ";
    }
    cout<<endl;*/
		int lenf=wyniknewtona+1;

//cout<<lenf<<endl;
Timer timer;
		getch();


    timer.start();
   reku(v2,vect1,vect2,vect3,vect4,mapa,0,maks,lenf,0,false,false,0,timer);





}














