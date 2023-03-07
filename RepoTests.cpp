#include "RepoTests.h"
#include <cassert>
#include <iostream>
#include "Repo.h"
void RepoTests::runAllTests()
{
    /**
     * .
     * function of running all the tests for the function from the repository
     */
    std::cout << "Repo.h test begin\n";
    std::cout << "Add test...\n ";
    addTest();
    std::cout << "Remove test... \n";
    removeTest();
    std::cout << "Edit test...\n";
    editTest();
    std::cout << "Repo.h test end\n";
}

int RepoTests::addTest()
{   
    /**
     * .
     * add test 
     * \return 
     */
    Repo* r = new Repo();
    Anime a;
    a.setEpisodes(1);
    a.setRating(69);
    a.setStudio("Wit");
    a.setTitle("Attack on Titan");
    r->add(a);
    assert(r->getAll().at(0).getEpisodes() == 1);
    assert(r->getAll().at(0).getRating() == 69);
    assert(r->getAll().at(0).getTitle() == "Attack on Titan");
    assert(r->getAll().at(0).getStudio() == "Wit");
    delete r;
    return 0;
}

int RepoTests::removeTest()
{
    /**
     * .
     * remove test
     * \return 
     */
    Repo* r = new Repo();
    Anime a;
    a.setEpisodes(1);
    a.setRating(69);
    a.setStudio("Wit");
    a.setTitle("Attack on Titan");
    r->add(a);
    r->remove(1);
    assert(r->getSize() == 0);
    delete r;
    return 0;
}

int RepoTests::editTest()
{
    /**
     * .
     * edit test
     * \return 
     */
    Repo* r = new Repo();
    Anime a,b;
    a.setEpisodes(1);
    a.setRating(69);
    a.setStudio("Wit");
    a.setTitle("Attack on Titan");
    r->add(a);
    b.setEpisodes(2);
    b.setRating(4);
    b.setStudio("f");
    b.setTitle("a");
    r->edit(0, b);
    assert(r->getAll().at(0).getEpisodes() == 2);
    assert(r->getAll().at(0).getRating() == 4);
    assert(r->getAll().at(0).getTitle() == "a");
    assert(r->getAll().at(0).getStudio() == "f");

    delete r;
    return 0;
}
