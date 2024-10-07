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
        * The MatrixView Class:
            - Contains A Constructor That Take Four Parameters:
                - The Matrix To Work On it, Row To Start From, Col To Start From, Number Of The Rows And The Number Of The Coloms Of That View. 
            - Copy Constructor To Create New Object Based On Another One.
            - Normal Assignement Constructor To Exchange Data Between Two Created Objects.;
            - Move Constructor Using.
            - Move Assigement Constructor.
            ## ALL OF THOSE CONSTRUCTORS USING THE SAME DATA.
            - Function To Get The Rows.
            - Function To Get The Cols.