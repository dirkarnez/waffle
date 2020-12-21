waffle
======
https://github.com/antlr/grammars-v4/tree/master/typescript
https://www.boost.org/doc/libs/1_68_0/libs/spirit/doc/x3/html/

Interface:                      'interface' ;


interfaceDeclaration
    : Interface Identifier objectType SemiColon?
    ;

objectType
    : '{' typeBody? '}'
    ;

typeBody
    : typeMemberList (SemiColon | ',')?
    ;

typeMemberList
    : typeMember ((SemiColon | ',') typeMember)*
    ;

typeMember
    : propertySignatur
    ;
