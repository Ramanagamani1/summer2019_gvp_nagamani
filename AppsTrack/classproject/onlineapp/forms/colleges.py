from onlineapp.models import College
from django import forms


class AddCollege(forms.ModelForm):
    class Meta:
        model=College
        exclude=['id']
        widgets={
            'name':forms.TextInput(attrs={'placeholder':'Enter name'}),
            'location': forms.TextInput(attrs={'placeholder': 'Enter location'}),
            'acronym': forms.TextInput(attrs={ 'placeholder': 'Enter acronym'}),
            'contact': forms.EmailInput(attrs={'placeholder': 'Enter contact'}),
      }
        pass