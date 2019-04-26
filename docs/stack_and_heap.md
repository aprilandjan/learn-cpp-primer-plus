# Stack and Heap

## auto variables

The variables declared in functions are stored automatically.

They are created at the beginning of belonging blocks, and auto-freed at the end of code blocks.

They are stored LIFO in a preserved continues memory, called **stack**.

## `new` allocated memories

When using `new` to allocate memories, these memories are persist util using corresponding `delete`

operator to free them manually.

They are program-dynamic stored in **heap**.

## reference

- *store persistance*, <c++ primer plus>, p304;
- *auto variable and stack*, <c++ primer plus>, p308;
- *dymanic allocate*, <c++ primer plus>, p320;