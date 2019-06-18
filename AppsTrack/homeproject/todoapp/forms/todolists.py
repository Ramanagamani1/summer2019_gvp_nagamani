from todoapp.models import todolist
from django import forms


class AddTodolist(forms.ModelForm):
    class Meta:
        model=todolist
        exclude=['id']
        widgets={
            'name':forms.TextInput(attrs={'placeholder':'Enter name'}),
            'created': forms.DateTimeInput(attrs={'placeholder': 'Enter date'}),
      }
        pass