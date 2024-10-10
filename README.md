## THIS REPOSITRY CONTAINS CODE SOURCE FOR THE PRE-SELECTION OF `1337 & Xcelerit XAD Hackathon 2024`

## So The Challnege Is About Create Two Classes:
* The Classes Are:
    - The Matrix Class, We Can Consider It As A Big Screen That Contains Number Of Pixeles Those We Set The When We Create It.
    - The Other Class Is The MatrixView Class And We Can Consider It As A Part From The Big Screen, And It Allows Us To Control The Part That We Choose From The Big Screen(Matrix).

        * The Matrix Class:
            - Contains A Constructor That Take Two Parameteres(Rows Numbers And Cols NUmbers), Provide Us Create A Matrix With Specific Width And Height.
            - Other Constructor Like The First One With One More Parametre(Init Value), To Fill The Matrix With Specific Value.
            - Copy Constructor To Create New Object Based On Another One Using Deep Copy.
            - Normal Assignement Constructor To Exchange Data Between Two Created Objects Using Deep Copy;
            - Move Constructor Using The Shallow Copy.
            - Move Assigement Constructor Using The Shallow Copy.
            - Constuctor To Create New Matrix From  The MatrixView.
            - Function To Get The Rows.
            - Function To Get The Cols.
            - Access Operator To Set Value In Spicefic Position In The Matrix And Check Value Of A Position.
        * The MatrixView Class:
            - Contains A Constructor That Take Four Parameters:
                - The Matrix To Work On it, Row To Start From, Col To Start From, Number Of The Rows And The Number Of The Cols Of That View. 
            - Copy Constructor To Create New Object Based On Another One.
            - Normal Assignement Constructor To Exchange Data Between Two Created Objects.;
            - Move Constructor Using.
            - Move Assigement Constructor.
            (ALL OF THOSE CONSTRUCTORS SHARE THE SAME UNDERLIYING DATA)
            - Function To Get The Rows.
            - Function To Get The Cols.
            - Access Operator To Set Value In Spicefic Position In The Matrix And Check Value Of A Position.

* So To Provide An Optimized Solution I Choose To Work With Only A Liner Array To Make Things Faster, And With Save The Real Number Of Cols And Rows I Follow This Relation To Keep My Access Operators Work As Expected ` Xpos * ColsNumber + YPos `.
* Also I Worked With A Fantastic Thing In C++ That Keep The Two Classes Objects Related When I Want Them To Do. It's The `shared_ptr`:
    - It Is a Smart Ptr That Retains Shared Ownership Of An Object Through A Pointer.
    - The shared_ptr Help Me To Work With My MatrixView Even If The Original Matrix Is Destroyed.
    - For More Infos [cppreference: shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr).

## EXAMPLES OF USE:
- To Create A Matrix **MTRX**:
    * `Matrix MTRX(10, 4);` or `Matrix MTRX(10, 4, 42);`
    * Now You Have A Matrix Of 10 Rows And 4 cols.
- To Check The Height And width Of The Matrix **MTRX**:
    * `std::cout <<  MTRX.rows() << ", " << MTRX.cols() << std::endl;`
    * The Expected Output Is: **10, 4**.
- To Insert Value In A Specific Position Like `x=8, y=3` in The **MTRX**:
    * `MTRX(8, 3) = 3.14;`
    * Now The Position `x=8, y=3` Should Contains The Value: `3.14`.
- To Check That Position:
    * `std::cout << MTRX(0, 0) << std::endl;`
    * The Expected Output Is `3.14`.
- To Create Other Independent Matrix **MTRX1** From Our **MTRX**:
    * `Matrix MTRX1(MTRX);`
- To Create Other  Matrix **MTRX2** From Our **MTRX** And Control One Of Them from The Other:
    * `Matrix MTRX2(std::move(MTRX));`

