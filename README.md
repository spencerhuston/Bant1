# Bant
Bant is an interpreted, statically typed, toy functional programming language made purely for my own entertainment

### Build:
Simply clone and run the ```makeBant.sh``` script. Run a Bant program using ```[bant directory]/build/bant [source file name].bnt```

### Features:
- first-class functions
- closures
- partial function application
- generic function parameters (to be templates)
- algebraic data types as _typeclass_ [Type]
- _int_, _char_, _string_, _bool_, and _null_ primitive types
- standard arithmetic and boolean operations
- _List_ type
- _Tuple_ type
- builtin functions for: _List_, _Tuple_, and _string_ manipulation, basic I/O
- control-flow statements
- pattern matching by value
- static type-checking
- comments
- external file importing

### TODO:
- Finish test suite (update as builtins and generics are finished)
- Finish builtin functions
- Implement templates in place of generics
- Fix type checking phase
- Add builtins list to this md
- Add documentation on language features
