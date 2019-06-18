import click
import os

@click.group()
def main():
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'homeproject.settings')
    import django
    django.setup()
    pass


@main.command()
def populatedb():
    todolists=['todolist1','todolist2','todolist3','todolist4','todolist5']
    from todoapp.models import todolist,todoitem
    for i in range(len(todolists)):
        c=todolist(name=todolists[i])
        c.save()

    for i in range(1,len(todolists)+1):
        for j in range(1,len(todolists)+1):
            c=todoitem(description="list"+str(i)+"item"+str(j),due_date='2019-06-15',completed=False)
            id_list=todolist.objects.all()
            for x in id_list:
                if x.id==i:
                   try:
                      c.todolists=todolist.objects.get(id=x.id)
                      c.save()
                   except ('IntegrityError', 'Error'):
                        continue


if __name__=='__main__':
    main()

