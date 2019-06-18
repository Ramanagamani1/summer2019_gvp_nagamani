from onlineapp.models import College,Student,MockTest1
from django import forms


class AddStudent(forms.ModelForm):
    class Meta:
       model=Student
       dropped_out: forms.BooleanField()
       exclude=['id','dob','college']
       fields=['name','email','db_folder','dropped_out']
       widgets={
           'name': forms.TextInput(attrs={'placeholder': 'Enter name'}),
           'email':forms.EmailInput(attrs={'placeholder': 'Enter email'}),
           'db_folder':forms.TextInput(attrs={'placeholder': 'Enter db_folder'}),
           'dropped_out':forms.CheckboxInput(attrs={'placeholder':'tick if yes'}),
        }


class AddStudentMarks(forms.ModelForm):
     class Meta:
         model=MockTest1
         exclude=['id','student','total']
         widgets={
             'problem1':forms.TextInput(attrs={'placeholder':'Enter score1'}),
             'problem2': forms.TextInput(attrs={'placeholder': 'Enter score2'}),
             'problem3': forms.TextInput(attrs={'placeholder': 'Enter score3'}),
             'problem4': forms.TextInput(attrs={'placeholder': 'Enter score4'}),
             #'total': forms.TextInput(attrs={'placeholder': 'Enter total'}),
         }