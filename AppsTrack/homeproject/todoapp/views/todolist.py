from django.shortcuts import render
from django.shortcuts import redirect
from todoapp.models import todolist,todoitem
from django.contrib.auth.mixins import LoginRequiredMixin
from django.views import View
from django.shortcuts import get_object_or_404
from todoapp.forms.todolists import AddTodolist
from django.urls import resolve

from todoapp.forms.todoitems import AddTodoitem

# Create your views here.


class TodoListView(LoginRequiredMixin,View):
    login_url = '/login/'

    def get(self, request, *args, **kwargs):
        if kwargs:
                   todo_list = todolist.objects.get(**kwargs)
                   todoitems= todoitem.objects.filter(todolists=todo_list.id)
                   #print(todoitems)
                   return render(
                    request,
                    template_name="todoapp/todoitem.html",
                    context={

                        'todo_list': todo_list,
                        'todoitems': todoitems,
                        'user_permissions': request.user.get_all_permissions(),

                    }
                  )

        todo_lists=todolist.objects.all()
        print(todo_lists)
        return render(
            request,
            template_name="todoapp/todolists.html",
            context={
                'todo_lists': todo_lists,
                'user_permissions': request.user.get_all_permissions(),
                'title': 'All todo_lists | Mentor App'
            }
        )


class AddTodoListView(LoginRequiredMixin,View):
    login_url = '/login/'
    def get(self, request, **kwargs):
        form=AddTodolist()
        if resolve(request.path_info).url_name=='edit_todolist':
            todo_list=todolist.objects.get(**kwargs)
            form=AddTodolist(instance=todo_list)
            return render(request, template_name='todoapp/addtodolist.html',
                      context={'form':form})

        if resolve(request.path_info).url_name=='delete_todolist':
             c=todolist.objects.get(pk=kwargs.get('pk')).delete()
             return redirect('todolists_html')

        return render(request, template_name='todoapp/addtodolist.html',
                      context={'form': form})

    def post(self, request, **kwargs):
        form = AddTodolist(request.POST)
        if resolve(request.path_info).url_name=='delete_todolist':
             c=todolist.objects.get(pk=kwargs.get('pk')).delete()
             return redirect('todolists_html')

        if resolve(request.path_info).url_name=='edit_todolist':
            todo_list=todolist.objects.get(**kwargs)
            form=AddTodolist(request.POST,instance=todo_list)
            if form.is_valid():
                form.save()
                return redirect('colleges_html')


        if form.is_valid():
            form.save()
            return redirect('todolists_html')

        return render(
            request,
            template_name='todoapp/addtodolist.html',

            context={'form':form,'title':'Add Todolists | MentorApp','user_permissions':request.user.get_all_permissions()}
        )
        pass

