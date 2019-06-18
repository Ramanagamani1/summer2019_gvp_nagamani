from todoapp.models import todolist,todoitem
from django import forms


class AddTodoitem(forms.ModelForm):
    class Meta:
       model=todoitem
       exclude=['id','todolists']
