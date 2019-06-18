from django.shortcuts import render
from django.shortcuts import redirect
from todoapp.models import todolist,todoitem
from django.contrib.auth.mixins import LoginRequiredMixin
from django.views import View
from django.shortcuts import get_object_or_404
from todoapp.forms.todolists import AddTodolist
from django.urls import resolve
from todoapp.forms.todoitems import AddTodoitem


class AddTodoItemView(LoginRequiredMixin,View):
    login_url = '/login/'

    def get(self, request, **kwargs):
        if resolve(request.path_info).url_name=='delete_todoitem':
             todoitem.objects.get(id=kwargs.get('pk')).delete()
             return redirect('todolists_html')

        form = AddTodoitem()

        if resolve(request.path_info).url_name=='edit_todoitem':
            s_id=todoitem.objects.get(id=kwargs['pk'])

            form=AddTodoitem(instance=s_id)
            return render(request, template_name='todoapp/addtodoitem.html',
                      context={'form':form})


        return render(request, template_name="todoapp/addtodoitem.html",
                      context={'form': form, 'user_permissions': request.user.get_all_permissions()})

    def post(self, request, **kwargs):

        form= AddTodoitem(request.POST)

        if resolve(request.path_info).url_name == 'edit_todoitem':
            s_id = todoitem.objects.get(id=kwargs['pk'])
            print(s_id.todolists_id)
            form = AddTodoitem(instance=s_id)
            print(form)
            if form.is_valid():
                form.save()
                return redirect('todolists_html',s_id.todolists_id)

        if form.is_valid():
             todo_list = get_object_or_404(todolist, id=kwargs.get('pk'))
             form = form.save(commit=False)
             form.todolists =todo_list
             form.save()
             return redirect('todoitems_html', kwargs['pk'])


        return render(
            request,
            template_name='todoapp/addtodoitem.html',
            context={'form': form,  'title': 'Add Todoitem | MentorApp',
                     'user_permissions': request.user.get_all_permissions()}
        )
