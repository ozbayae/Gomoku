// file gobord.h
class bordvakje {
  public:
    char kleur;           //     7 0 1
    bordvakje* buren[8];  //     6   2
    bordvakje ( );        //     5 4 3
};//bordvakje

class gobord {
  private:
    bordvakje* ingang;
    int hoogte, breedte;
    bordvakje* maakrij();
    void ritsen(bordvakje* boven, bordvakje* onder);
    void drukafburen(bordvakje*);
    // TODO
  public:
    gobord ( );
    gobord (int hoogte, int breedte);
    ~gobord ( );
    void drukaf ( );
    void maakbord ( );
    // TODO
};//gobord
