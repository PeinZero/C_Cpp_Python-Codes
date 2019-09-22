class Data
{ 
    public:
    int f(float) 
    { 
        return 1; 
    }
};

int (Data::*fp1) (float) = &Data::f;   // Declaration and assignment
int (Data::*fp2) (float);        // Only Declaration

int main()
{
    fp2 = &Data::f;   // Assignment inside main()
}
