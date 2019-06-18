import readline

def main():
    for i in range(readline.get_current_history_length()):
         print (readline.get_history_item(i + 1))


if __name__=='__main__':
    from django.db import connection as conn

    print(conn.queries)
    main()
