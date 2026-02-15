#ifndef __ARTICLES_H__
#define __ARTICLES_H__

#include <iostream>

class Articles
{

private:
    
    char* MagazineName;
    char* articleName;
    int publicationDate;
    
public:

    Articles (const char* MagazineName ,const char* articleName, int publicationDate);///constrastor
    Articles(const Articles& other);//copy constrastor
    Articles( Articles&& other);
    const Articles& operator=(const Articles& other);
    Articles& operator=( Articles&& other);
    ~Articles();  //disconstrastor

    friend std::ostream& operator<< (std::ostream& os,const Articles& a);

    const char* getMagazineName()   const {return MagazineName;}
    const char* getarticleName()   const {return articleName;}
    int getpublicationDate()      const {return publicationDate;}

    bool setMagazineName(const char* name);
    bool setarticleName(const char* name);
    //bool setpublicationDate(const int publicationDate);





    
};






#endif
