//数组实现声明
typedef struct{
    int CoeffArray[ NaxDegree + 1];
    int HighPower;
} *Polynomial;

//初始化为0
void ZeroPolynomial( Polynomial Poly){
    int i;
    for( i=0; i <= MaxDegree; i++)
        Poly->CoeffArray[ i] = 0;
    Poly->HighPower = 0;
}

//相加
void AddPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                   Polynomial PolySum){
    int i;
    ZeroPolynomial( PolySum);
    PolySum->HighPower = Poly1->HighPower > Poly2->HighPower ? Poly1->HighPower : Poly2->HighPower;
    for( i = PolySum->HighPower; i >= 0; i--){
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
}

//相乘
void MultPolynomial( const Polynomial Poly1, const Polynomial Poly2,
                   Polynomial PolyProd){
    int i, j;
    ZeroPolynomial( PolyProd);
    PolyProd->HighPower = Poly1->HighPower * Poly2->HighPower;
    if( PolyProd->HighPower > MaxDegree)
        Error("Exceeded array size");
    else 
        for( i = 0; i < Poly1->HighPower; i++)
            for( j = 0; j < Poly2->HighPower; j++)
                PolySum->CoeffArray[ i+j] = Poly1->CoeffArray[i] + Poly2->CoeffArray[j];
}