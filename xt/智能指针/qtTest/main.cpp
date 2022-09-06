#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <memory>
#include <share_ptr_example.h>
#include <weak_ptr.h>

using namespace std;

unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
{
    // Implicit move operation into the variable that stores the result.
    return make_unique<Song>(artist, title);
}

void MakeSongs()
{
    // Create a new unique_ptr with a new object.
    auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

    // Use the unique_ptr.
    vector<wstring> titles = { song->title };

    // Move raw pointer from one unique_ptr to another.
    unique_ptr<Song> song2 = std::move(song);

    // Obtain unique_ptr from function that returns by value.
    auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
}

void SongVector()
{
    vector<unique_ptr<Song>> songs;

    // Create a few new unique_ptr<Song> instances
    // and add them to vector using implicit move semantics.
    songs.push_back(make_unique<Song>(L"B'z", L"Juice"));
    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town"));
    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de"));
    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));

    // Pass by const reference when possible to avoid copying.
    for (const auto& song : songs)
    {
       wcout << L"Artist: " << song->artist << L"   Title: " << song->title << endl;
    }
    // Create a unique_ptr to an array of 5 integers.
    auto p=make_unique<int[]>(5);

    for(int i=0;i<5;++i)
    {
        p[i] = i;
        wcout << p[i] << endl;
    }
}


int main()
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    //示例1
    // Use make_shared function when possible.
    auto sp1=std::make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

    // Ok, but slightly less efficient.
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    std::shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");

    //实例2
    //Initialize with copy constructor. Increments ref count.
    auto sp3(sp2);

    //Initialize via assignment. Increments ref count.
    auto sp4 = sp2;

    //Initialzie with another shared_ptr,sp1 and sp2
    //swap pointers as well as ref counts
     sp1.swap(sp2);

     //operator remove_copyt_if
     vector<shared_ptr<Song>> v{
            make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
            make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
            make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")
     };

     vector<shared_ptr<Song>> v2;

     remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
     {
         return s->artist.compare(L"Bob Dylan") == 0;
     });

     for (const auto& s : v2)
     {
         wcout << s->artist << L":" << s->title << endl;
     }

//     您可以使用 dynamic_pointer_cast、static_pointer_cast 和
//     const_pointer_cast 来转换 shared_ptr。
//     这些函数类似于 dynamic_cast、static_cast 和
//     const_cast 运算符。
//     以下示例演示如何测试基类的 shared_ptr 向量中每个元素的派生类型，
//     然后复制元素并显示有关它们的信息。
     vector<shared_ptr<MediaAsset>> assets {
       make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
       make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
       make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
     };

     vector<shared_ptr<MediaAsset>> photos;

     copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (shared_ptr<MediaAsset> p) -> bool
     {
         // Use dynamic_pointer_cast to test whether
         // element is a shared_ptr<Photo>.
         shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
         return temp.get() != nullptr;
     });

     for (const auto&  p : photos)
     {
         // We know that the photos vector contains only
         // shared_ptr<Photo> objects, so use static_cast.
         wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
     }

     // Initialize two separate raw pointers.
     // Note that they contain the same values.
     auto song1 = new Song(L"Village People", L"YMCA");
     auto song2 = new Song(L"Village People", L"YMCA");

     // Create two unrelated shared_ptrs.
     shared_ptr<Song> p1(song1);
     shared_ptr<Song> p2(song2);

     // Unrelated shared_ptrs are never equal.
     wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
     wcout << "p1 == p2 = " << std::boolalpha <<(p1 == p2) << endl;

     // Related shared_ptr instances are always equal.
     shared_ptr<Song> p3(p2);
     wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;

    MakeSongs();

    RunTest();

    std::shared_ptr<A> a(new A());
    std::shared_ptr<B> b(new B());

    a->b_ptr=b;
    b->a_ptr=a;

    std::cout<<"A: "<<a.use_count()<<"\n";
    std::cout<<"B: "<<b.use_count()<<"\n";
}
