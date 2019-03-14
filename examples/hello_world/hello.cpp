#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <iostream>

class my_hello_world : public cppcms::application {
public:
    my_hello_world(cppcms::service &srv) :
        cppcms::application(srv) 
    {
    }
    virtual void main(std::string url);
};

void my_hello_world::main(std::string /*url*/)
{
    cppcms::json::value my_object;
    // Create object data
    my_object["name"]="Moshe";
    my_object["salary"]=1000.0;
    my_object["kids_names"][0]="Yossi";
    my_object["kids_names"][1]="Yonni";
    
    response().out() << my_object;
}

int main(int argc,char ** argv)
{
    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<my_hello_world>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr<<e.what()<<std::endl;
    }
}
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
