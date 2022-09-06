#ifndef SHARE_PTR_EXAMPLE_H
#define SHARE_PTR_EXAMPLE_H
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    virtual ~MediaAsset()=default;
};


struct Song:public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_,const std::wstring& title_):
        artist{artist_},title{title_}{}
};

struct Photo:public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_
        ):date{date_},location{location_},subject{subject_}{}
};
//share_ptr和unique_ptr的例子

class Object
{
protected:
    int id;

public:
    using pointer=std::shared_ptr<Object>;

    virtual std::string version() const{
        return "1.0.0";
    }

    Object(int _id):id(_id){
        std::cout << "\nnew parent Object id:" << id  << std::endl;
    }

    virtual ~Object(){
        delete parent_str_ptr;
        std::cout<<"delete parent Object id:"<<id<<std::endl;
    }

    virtual std::string debug() const
    {
        auto str = std::string( "debug Object id:" + std::to_string(id) );
        return str;
    }

private:
    std::string *parent_str_ptr = new std::string("parent_str_ptr memory leak");
};


class ChildObject:public Object
{
public:
      ChildObject(int _id):Object(_id)
      {
          std::cout<<"New ChildObject id:"<<(id)<<"\n";
      }

      ~ChildObject()
      {
          delete str_ptr;
          std::cout<<"delete ChildObject id:"<<id<<"\n";
      }

      virtual std::string version() const{
          return "2.0.0";
      }
private:
      std::string *str_ptr=new std::string("memory leak");
};

void testObject(const Object &obj)
{
    std::cout<<obj.debug()<<" version:"<<obj.version()<<"\n"<<std::endl;
}

void testCase()
{
    {
        std::shared_ptr<Object> sObj = std::make_shared<ChildObject>(1);
        testObject(*sObj); //调用父对象
    }
    {
        std::unique_ptr<Object> obj = std::make_unique<ChildObject>(2);
        testObject(*obj);

        auto obj2=std::move(obj);//转移所有权到Ojb2

        testObject(*obj2);//调用父对象

    //    printf("obj:%s obj2:%s \n", formatBool(!!obj), formatBool(!!obj2));
        obj2.release();
        obj2.release();//手动释放后， obj, obj2指向的对象已经被回收， 不会触发自动回收
    //     printf("obj2.release， obj:%s obj2:%s \n", formatBool(!!obj), formatBool(!!obj2));
    }

    {
        std::unique_ptr<ChildObject> obj = std::make_unique<ChildObject>(3);// 使用make_unique
        testObject(*obj);
        //printf("release3 %s \n", formatBool(!!obj));
    }
    {
        std::unique_ptr<ChildObject> obj(new ChildObject(4));//使用new
        testObject(*obj);
        //printf("release4 %s \n", formatBool(!!obj));
    }

    {
        // std::unique_ptr<ChildObject> obj(ChildObject(5));//使用stack对象，这是错误的用法， error: no matching constructor for initialization of 'std::unique_ptr<Object>'
        // printf("release5 %d \n", !!obj);
    }

    {
        std::unique_ptr<Object> obj = std::make_unique<ChildObject>(6);//用父对象, 会触发析构
        testObject(*obj);
        //printf("release6 %s \n", formatBool(!!obj));
    }

    {
        ChildObject obj = ChildObject(7);//从stack分配原始对象， 会触发析构
        testObject(obj);
        printf("release7 %p \n", &obj);
    }

    {
        ChildObject * obj = new ChildObject(8);//从heap分配原始对象， 必须手动触发析构
        testObject(*obj);
        printf("release8 %p \n", obj);
        delete obj;
    }

    {
        Object * obj = new Object(10);//从heap分配原始父对象，必须手动触发析构
        testObject(*obj);
        printf("release10 %p \n", obj);
        delete obj;
    }

    {
        std::shared_ptr<Object> obj = std::make_unique<ChildObject>(11);//指向父对象, 会释放子对象
        testObject(*obj);
        //printf("release11 %s \n", formatBool(!!obj));
    }
}
#endif // SHARE_PTR_EXAMPLE_H
