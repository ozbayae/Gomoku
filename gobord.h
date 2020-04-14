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
    // TODO
  public:
    gobord ( );
    gobord (int hoogte, int breedte);
    ~gobord ( );
    void drukaf ( );
    // TODO
};//gobord
