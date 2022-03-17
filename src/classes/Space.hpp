class Space {
   private:
    int height;
    int width;

    bool** createMap(int h, int w);

   public:
    bool** array;
    Space(int, int);
    ~Space();

    int countAround(int x, int y);
    void update();
    void show();

};
