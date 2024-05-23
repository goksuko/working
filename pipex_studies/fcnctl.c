The "Bad file descriptor" error typically occurs when you're trying to perform an operation (like `read`, `write`, `close`, etc.) on a file descriptor that is not open.

In your code, you're using `dup2` to duplicate file descriptors and `close` to close them. If you're trying to duplicate or close a file descriptor that is not open, you'll get a "Bad file descriptor" error.

Here are a few things you can check:

1. Make sure `info->fd_in`, `info->fd_out`, and `info->pipefd[0]` and `info->pipefd[1]` are open before you use them with `dup2` or `close`. You can use the `fcntl` function with the `F_GETFD` command to check if a file descriptor is open:

    ```c
    if (fcntl(info->fd_in, F_GETFD) == -1) {
        perror("info->fd_in is not open");
    }
    ```

    This will print an error message if `info->fd_in` is not open.

2. Make sure you're not closing a file descriptor more than once. Once a file descriptor is closed, it cannot be used again. If you try to close it again, you'll get a "Bad file descriptor" error.

3. Make sure you're not using a file descriptor after it's been closed. Once a file descriptor is closed, it cannot be used again. If you try to use it after it's been closed, you'll get a "Bad file descriptor" error.

4. Make sure the `start_exec` function is not closing or otherwise modifying the file descriptors. If `start_exec` closes a file descriptor, it will not be open in the parent process after `start_exec` returns.

If you're still having trouble, you can add error checking to the `dup2` and `close` calls to see which one is causing the error:

```c
if (dup2(info->fd_in, STDIN_FILENO) == -1) {
    perror("dup2 failed");
}
if (close(info->fd_in) == -1) {
    perror("close failed");
}
```

This will print an error message if `dup2` or `close` fails.