echo "1. ex1 of subject"
< ./Libft ls -l | wc -l > result.txt
./pipex ./Libft "ls -l" "wc -l" result2.txt
diff result.txt result2.txt
echo "now memory check for 1"
echo ""
valgrind ./pipex ./Libft "ls -l" "wc -l" result2.txt
echo "1st Done"
echo ""

echo "2. ex2 of subject"
< test.txt grep a1 | wc -w > result.txt
./pipex test.txt "grep a1" "wc -w" result2.txt
diff result.txt result2.txt
echo "now memory check for 2"
echo ""
valgrind ./pipex test.txt "grep a1" "wc -w" result2.txt
echo "2nd Done"
echo ""

echo "3. absolute path as a cmd"
< test.txt ./usr/bin/ls/ | wc -l > result.txt
./pipex test.txt "./usr/bin/ls/" "wc -l" result2.txt
diff result.txt result2.txt
echo "now memory check for 3"
echo ""
valgrind ./pipex test.txt "./usr/bin/ls/" "wc -l" result2.txt
echo "3rd Done"
echo ""

echo "4. binary file as a cmd"
echo "4th org"
< test.txt ./checker_linux | grep a > result.txt
echo  "4th mine"
./pipex test.txt "./checker_linux" "grep a" result2.txt
diff result.txt result2.txt
echo "now memory check for 4"
echo ""
valgrind ./pipex test.txt "./checker_linux" "grep a" result2.txt
echo "4th Done"
echo ""

echo "5. unset PATH"
echo "5th org"
unset PATH
< ./Libft ls -l | wc -l > result.txt
echo "5th mine"
unset PATH
./pipex ./Libft "ls -l" "wc -l" result2.txt
diff result.txt result2.txt
echo "now memory check for 5"
echo ""
valgrind ./pipex ./Libft "ls -l" "wc -l" result2.txt
echo "5th Done"
echo ""

echo "6. empty cmd"
echo "6th org"
< test.txt "" | wc -l > result.txt
echo "6th mine"
./pipex test.txt "" "wc -l" result2.txt
diff result.txt result2.txt
echo "now memory check for 6"
echo ""
valgrind ./pipex test.txt "" "wc -l" result2.txt
echo "6th Done"
echo ""

echo "7. empty file"
echo "7th org"
< empty.txt ls -l | wc -l > result.txt
echo "7th mine"
./pipex empty.txt "ls -l" "wc -l" result2.txt
diff result.txt result2.txt
echo "now memory check for 7"
echo ""
valgrind ./pipex empty.txt "ls -l" "wc -l" result2.txt
echo "7th Done"
echo ""

echo "8. big file"

echo "9. exit number"

echo "10. one space cmd"
echo "10th org"
< test.txt " " | wc -l > result.txt
echo "10th mine"
./pipex test.txt " " "wc -l" result2.txt
diff result.txt result2.txt
echo "now memory check for 10"
echo ""
valgrind ./pipex test.txt " " "wc -l" result2.txt
echo "10th Done"
echo ""



