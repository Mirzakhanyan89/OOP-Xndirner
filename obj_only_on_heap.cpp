class B
{
    B(){}   
    public:
    static B* Create()
    {

        return new B();
    }

};

int main() {
    //B S;
    B* b = B::Create();

    return 0;
}
